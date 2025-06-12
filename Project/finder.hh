/**
 * @file finder.hh
 * @brief Estructura espacial de cèl·lules per indexar i cercar objectes segons la seva àrea.
 * 
 * Aquesta classe permet afegir, eliminar i actualitzar objectes que implementin el mètode
 * get_rect(), així com fer consultes d'intersecció dins d'una regió Rectangle.
 */
#ifndef FINDER_HH
#define FINDER_HH

#include "window.hh"
#include <set>

/**
 * @brief Template per a la cerca d'objectes dins d'un espai 2D fragmentat en cèl·lules.
 * 
 * El Finder divideix l'espai mundial en una graella de cèl·lules fixades (CELL_W x CELL_H)
 * i manté llistes d'objectes dins de cada cèl·lula per permetre consultes ràpides segons
 * rectangles d'intersecció.
 *
 * @tparam T Tipus d'objecte amb mètode get_rect() que retorna un pro2::Rect.
 */
template<typename T>
class Finder {
 private:
    // Amplada de cada cèl·lula en píxels
    static const int CELL_W = 960;
    // Alçada de cada cèl·lula en píxels
    static const int CELL_H = 640;

    // Nombre de columnes de la graella
    int cols_;
    // Nombre de files de la graella
    int rows_;

    /**
     * @brief Node enllaçat dins d'una cèl·lula de la graella.
     *
     * Emmagatzema un punter a l'objecte i enllaços a l'anterior i següent dins la llista
     * circular de la cèl·lula.
     */
    struct CellNode {
        T*        obj;  // Punter a l'objecte indexat
        CellNode* next; // Següent node dins la cèl·lula
        CellNode* prev; // Node anterior dins la cèl·lula
        CellNode(T* o) : obj(o), next(nullptr), prev(nullptr) {}
    };

    /**
     * @brief Node dins la llista d'entrades d'un objecte en totes les cèl·lules.
     *
     * Cada objecte pot aparèixer en diverses cèl·lules; ObjNode conté el punter
     * al CellNode corresponent.
     */
    struct ObjNode {
        CellNode* cell_node; // Punter al node dins la cèl·lula
        ObjNode*  next;      // Següent entrada per al mateix objecte
        ObjNode(CellNode* cn) : cell_node(cn), next(nullptr) {}
    };

    /**
     * @brief Registre per a cada objecte afegit al Finder.
     *
     * Conté l'objecte, la llista d'ObjNode (una per cada cèl·lula implicada) i
     * enllaços dobles per recórrer tots els registres.
     */
    struct ObjRecord {
        T*         obj;  // Punter a l'objecte gestionat
        ObjNode*   head; // Cap de la llista d'entrades ObjNode
        ObjRecord* next; // Següent registre en la llista circular
        ObjRecord* prev; // Registre anterior en la llista circular
        ObjRecord(T* o) : obj(o), head(nullptr), next(nullptr), prev(nullptr) {}
    };

    // Array de sentinelles per a cada cèl·lula (llista circular)
    CellNode** grid_heads_;
    // Sentinella de la llista circular de registres d'objectes
    ObjRecord  obj_sentinel_;

    /**
     * @brief Limita un valor dins un rang [lo, hi].
     * @param v Valor a limitar
     * @param lo Lím inferior
     * @param hi Límit superior
     * @return Valor "clampat" dins del rang
     */
    int clamp(int v, int lo, int hi) const {
        if (v < lo) return lo;
        else if (v > hi) return hi;
        else return v;
    }

    /**
     * @brief Calcula el rang de cèl·lules que cobreix un rectangle.
     *
     * Converteix coordenades en píxels a índexs de cèl·lules i aplica clamp
     * per garantir que es trobin dins la graella.
     *
     * @param r Rectàngle a indexar
     * @param[out] cx0 Índex de columna mínim
     * @param[out] cy0 Índex de fila mínim
     * @param[out] cx1 Índex de columna màxim
     * @param[out] cy1 Índex de fila màxim
     */
    void compute_cells(const pro2::Rect& r, int& cx0,int& cy0,int& cx1,int& cy1) const {
        cx0 = r.left   / CELL_W;
        cy0 = r.top    / CELL_H;
        cx1 = r.right  / CELL_W;
        cy1 = r.bottom / CELL_H;
        // Ajusta dins la graella
        cx0 = clamp(cx0, 0, cols_-1);
        cy0 = clamp(cy0, 0, rows_-1);
        cx1 = clamp(cx1, 0, cols_-1);
        cy1 = clamp(cy1, 0, rows_-1);
    }

 public:
    /**
     * @brief Constructor de Finder.
     *
     * Inicialitza la graella de cèl·lules segons les dimensions de món passades.
     * @param world_w Amplada total del món (píxels). Per defecte CELL_W.
     * @param world_h Alçada total del món (píxels). Per defecte CELL_H.
     */
    Finder(int world_w = CELL_W, int world_h = CELL_H)
        : cols_((world_w + CELL_W -1)/CELL_W), rows_((world_h + CELL_H-1)/CELL_H), obj_sentinel_(nullptr) {
        // Inicialitza la llista circular d'objectes
        obj_sentinel_.next = &obj_sentinel_;
        obj_sentinel_.prev = &obj_sentinel_;
        // Crea sentinelles de cèl·lula
        grid_heads_ = new CellNode*[cols_*rows_];
        for(int i=0;i<cols_*rows_;++i) {
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
        // Elimina tots els registres i entrades
        ObjRecord* rec = obj_sentinel_.next;
        while(rec != &obj_sentinel_) {
            ObjNode* on = rec->head;
            while(on) {
                CellNode* cn = on->cell_node;
                // Desenllaça de la cèl·lula
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
        // Elimina sentinelles de cèl·lula
        for(int i=0;i<cols_*rows_;++i)
            delete grid_heads_[i];
        delete[] grid_heads_;
    }

    /**
     * @brief Afegeix un objecte al Finder.
     *
     * Indexa l'objecte en totes les cèl·lules que cobreix el seu rectangle.
     * @param t Punter a l'objecte que implementa get_rect().
     */
    void add(T* t) {
        int cx0,cy0,cx1,cy1;
        compute_cells(t->get_rect(), cx0,cy0,cx1,cy1);
        ObjRecord* rec = new ObjRecord(t);
        // Insereix el registre en la llista circular
        rec->next = obj_sentinel_.next;
        rec->prev = &obj_sentinel_;
        obj_sentinel_.next->prev = rec;
        obj_sentinel_.next = rec;
        // Crea entrades per a cada cèl·lula afectada
        for(int x=cx0;x<=cx1;++x) for(int y=cy0;y<=cy1;++y) {
            int idx = y*cols_ + x;
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

    /**
     * @brief Elimina un objecte del Finder.
     *
     * Desenllaça i allibera totes les entrades de cèl·lula associades i esborra
     * el registre d'objecte.
     * @param t Punter a l'objecte a eliminar.
     */
    void remove(T* t) {
        for(ObjRecord* rec = obj_sentinel_.next; rec!=&obj_sentinel_; rec=rec->next) {
            if(rec->obj == t) {
                // Esborra les entrades de cèl·lula
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
                // Desenllaça el registre i allibera
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
     * @brief Consulta tots els objectes que intersecten un rectangle donat.
     *
     * Retorna un conjunt d'objectes amb intersecció no buida respecte al rectangle.
     * @param rect Regió de consulta
     * @return std::set<T*> Conjunt d'objectes trobats.
     */
    std::set<T*> query(pro2::Rect rect) const {
        std::set<T*> result;
        int cx0,cy0,cx1,cy1;
        compute_cells(rect, cx0,cy0,cx1,cy1);
        for(int x=cx0;x<=cx1;++x) {
            for(int y=cy0;y<=cy1;++y) {
                int idx = y*cols_ + x;
                CellNode* sent = grid_heads_[idx];
                for(CellNode* cn = sent->next; cn!=sent; cn=cn->next) {
                    auto r2 = cn->obj->get_rect();
                    if(rect.left <= r2.right and r2.left <= rect.right and rect.top  <= r2.bottom and r2.top <= rect.bottom) {
                        result.insert(cn->obj);
                    }
                }
            }
        }
        return result;
    }
};

#endif // FINDER_HH
