/**
 * @file finder.hh
 * @brief Estructura espacial per indexar i cercar objectes en un espai 2D fragmentat en cèl·lules.
 *
 * La plantilla Finder divideix l'espai mundial en una graella de cèl·lules fixes
 * (CELL_W × CELL_H) i manté llistes d'objectes dins de cada cèl·lula, permetent
 * consultes ràpides d'intersecció dins d'una regió.
 */
#ifndef FINDER_HH
#define FINDER_HH

#include "window.hh"
#include <set>

/**
 * @class Finder
 * @brief Cercador d'objectes en una graella espacial de cèl·lules.
 *
 * @tparam T Tipus d'objecte que defineix get_rect() retornant un pro2::Rect.
 *
 * Proporciona operacions d'afegir, eliminar, actualitzar i consultar objectes
 * segons el rectangle que cobreixen. Cada objecte s'indexa en totes les cèl·lules
 * que intersecta, i les operacions són eficients per espais grans.
 */
template<typename T>
class Finder {
 private:
    /// Amplada de cada cèl·lula (píxels).
    static const int CELL_W = 960;
    /// Alçada de cada cèl·lula (píxels).
    static const int CELL_H = 640;

    /// Nombre de columnes de la graella.
    int cols_;
    /// Nombre de files de la graella.
    int rows_;

    /**
     * @struct CellNode
     * @brief Node enllaçat dins d'una cèl·lula de la graella.
     *
     * Emmagatzema un punter a l'objecte i enllaços a
     * l'anterior i següent dins la llista circular de la cèl·lula.
     */
    struct CellNode {
        T*        obj;   ///< Punter a l'objecte indexat.
        CellNode* next;  ///< Següent node dins la cèl·lula.
        CellNode* prev;  ///< Node anterior dins la cèl·lula.
        CellNode(T* o) : obj(o), next(nullptr), prev(nullptr) {}
    };

    /**
     * @struct ObjNode
     * @brief Entrada en polítiques de cèl·lula per un objecte.
     *
     * Cada objecte pot aparèixer en diverses cèl·lules; ObjNode conté
     * el punter al CellNode corresponent.
     */
    struct ObjNode {
        CellNode* cell_node;  ///< Punter al node dins la cèl·lula.
        ObjNode*  next;       ///< Següent entrada per al mateix objecte.
        ObjNode(CellNode* cn) : cell_node(cn), next(nullptr) {}
    };

    /**
     * @struct ObjRecord
     * @brief Registre d'un objecte dins el Finder.
     *
     * Conté l'objecte, la llista d'entrades ObjNode (una per cada cèl·lula
     * implicada) i enllaços dobles per recórrer tots els registres.
     */
    struct ObjRecord {
        T*         obj;   ///< Punter a l'objecte gestionat.
        ObjNode*   head;  ///< Cap de la llista d'entrades ObjNode.
        ObjRecord* next;  ///< Següent registre en la llista circular.
        ObjRecord* prev;  ///< Registre anterior en la llista circular.
        ObjRecord(T* o) : obj(o), head(nullptr), next(nullptr), prev(nullptr) {}
    };

    /// Array de sentinelles per a cada cèl·lula (llistes circulars).
    CellNode** grid_heads_;
    /// Sentinella de la llista circular de registres d'objectes.
    ObjRecord  obj_sentinel_;

    /**
     * @brief Limita un valor dins el rang [lo, hi].
     * @param v Valor a limitar.
     * @param lo Lím inferior.
     * @param hi Lím superior.
     * @return Valor "clampat" dins el rang.
     */
    int clamp(int v, int lo, int hi) const {
        if (v < lo) return lo;
        else if (v > hi) return hi;
        else return v;
    }

    /**
     * @brief Calcula el rang de cèl·lules per a un rectangle.
     *
     * Converteix coordenades en píxels a índexs de cèl·lules i aplica clamp
     * per garantir que els índexs siguin vàlids.
     *
     * @param r Rectangle a indexar.
     * @param[out] cx0 Índex de columna mínim.
     * @param[out] cy0 Índex de fila mínim.
     * @param[out] cx1 Índex de columna màxim.
     * @param[out] cy1 Índex de fila màxim.
     */
    void compute_cells(const pro2::Rect& r,
                       int& cx0, int& cy0,
                       int& cx1, int& cy1) const {
        cx0 = r.left   / CELL_W;
        cy0 = r.top    / CELL_H;
        cx1 = r.right  / CELL_W;
        cy1 = r.bottom / CELL_H;
        cx0 = clamp(cx0, 0, cols_-1);
        cy0 = clamp(cy0, 0, rows_-1);
        cx1 = clamp(cx1, 0, cols_-1);
        cy1 = clamp(cy1, 0, rows_-1);
    }

 public:
    /**
     * @brief Constructor de Finder.
     *
     * Inicialitza la graella de cèl·lules segons les dimensions del món.
     * @param world_w Amplada total del món (píxels). Per defecte CELL_W.
     * @param world_h Altura total del món (píxels). Per defecte CELL_H.
     */
    Finder(int world_w = CELL_W, int world_h = CELL_H)
        : cols_((world_w + CELL_W -1)/CELL_W),
          rows_((world_h + CELL_H -1)/CELL_H),
          obj_sentinel_(nullptr) {
        obj_sentinel_.next = &obj_sentinel_;
        obj_sentinel_.prev = &obj_sentinel_;
        grid_heads_ = new CellNode*[cols_*rows_];
        for(int i = 0; i < cols_*rows_; ++i) {
            grid_heads_[i] = new CellNode(nullptr);
            grid_heads_[i]->next = grid_heads_[i];
            grid_heads_[i]->prev = grid_heads_[i];
        }
    }

    /**
     * @brief Destructor de Finder.
     *
     * Allibera tots els nodes de cèl·lula i registres d'objectes.
     */
    ~Finder() {
        ObjRecord* rec = obj_sentinel_.next;
        while(rec != &obj_sentinel_) {
            ObjNode* on = rec->head;
            while(on) {
                CellNode* cn = on->cell_node;
                cn->prev->next = cn->next;
                cn->next->prev = cn->prev;
                delete cn;
                ObjNode* next_on = on->next;
                delete on;
                on = next_on;
            }
            ObjRecord* next_rec = rec->next;
            delete rec;
            rec = next_rec;
        }
        for(int i = 0; i < cols_*rows_; ++i) delete grid_heads_[i];
        delete[] grid_heads_;
    }

    /**
     * @brief Afegeix un objecte al Finder.
     *
     * Indexa l'objecte en totes les cèl·lules que cobreix el seu rectangle.
     * @param t Punter a un objecte que implementa get_rect().
     */
    void add(T* t) {
        int cx0, cy0, cx1, cy1;
        compute_cells(t->get_rect(), cx0, cy0, cx1, cy1);
        ObjRecord* rec = new ObjRecord(t);
        rec->next = obj_sentinel_.next;
        rec->prev = &obj_sentinel_;
        obj_sentinel_.next->prev = rec;
        obj_sentinel_.next = rec;
        for(int x = cx0; x <= cx1; ++x) {
            for(int y = cy0; y <= cy1; ++y) {
                int idx = y * cols_ + x;
                CellNode* sent = grid_heads_[idx];
                CellNode* cn = new CellNode(t);
                cn->next = sent;
                cn->prev = sent->prev;
                sent->prev->next = cn;
                sent->prev = cn;
                ObjNode* on = new ObjNode(cn);
                on->next = rec->head;
                rec->head = on;
            }
        }
    }

    /**
     * @brief Elimina un objecte del Finder.
     *
     * Desenllaça i allibera totes les entrades de cèl·lula associades i
     * esborra el registre de l'objecte.
     * @param t Punter a l'objecte a eliminar.
     */
    void remove(T* t) {
        for(ObjRecord* rec = obj_sentinel_.next; rec != &obj_sentinel_; rec = rec->next) {
            if(rec->obj == t) {
                ObjNode* on = rec->head;
                while(on) {
                    CellNode* cn = on->cell_node;
                    cn->prev->next = cn->next;
                    cn->next->prev = cn->prev;
                    delete cn;
                    ObjNode* next_on = on->next;
                    delete on;
                    on = next_on;
                }
                rec->prev->next = rec->next;
                rec->next->prev = rec->prev;
                delete rec;
                return;
            }
        }
    }

    /**
     * @brief Actualitza la posició d'un objecte al Finder.
     *
     * Elimina l'objecte i el torna a afegir per recalcular les cèl·lules que ocupa.
     * @param t Punter a l'objecte a actualitzar.
     */
    void update(T* t) {
        remove(t);
        add(t);
    }

    /**
     * @brief Consulta tots els objectes que intersecten un rectangle.
     *
     * Retorna un conjunt d'objectes amb intersecció no buida amb la regió.
     * @param rect Regió de consulta (pro2::Rect).
     * @return std::set<T*> Conjunt d'objectes trobats.
     */
    std::set<T*> query(pro2::Rect rect) const {
        std::set<T*> result;
        int cx0, cy0, cx1, cy1;
        compute_cells(rect, cx0, cy0, cx1, cy1);
        for(int x = cx0; x <= cx1; ++x) {
            for(int y = cy0; y <= cy1; ++y) {
                int idx = y * cols_ + x;
                CellNode* sent = grid_heads_[idx];
                for(CellNode* cn = sent->next; cn != sent; cn = cn->next) {
                    auto r2 = cn->obj->get_rect();
                    if(rect.left <= r2.right && r2.left <= rect.right &&
                       rect.top  <= r2.bottom && r2.top <= rect.bottom) {
                        result.insert(cn->obj);
                    }
                }
            }
        }
        return result;
    }
};

#endif // FINDER_HH