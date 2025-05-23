#ifndef FINDER_HH
#define FINDER_HH

#include "window.hh"
using namespace pro2;

#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

template <typename T>
class Finder {
 private:
    // Ancho de cada celda de la cuadrícula (en píxels).
    const int width_  = 960;
    // Alto de cada celda de la cuadrícula (en píxels).
    const int height_ = 640;

    /**
     * @brief Mapa de objeto a lista de celdas que ocupa.
     *
     * Clave: puntero al objeto T.
     * Valor: vector de pares (x, y) de celdas.
     */
    map<const T*, vector<pair<int, int>>> obj_;
    /**
     * @brief Mapa de celda a conjunto de objetos que la ocupan.
     *
     * Clave: par (x, y).
     * Valor: conjunto de punteros a T en esa celda.
     */
    map<pair<int, int>, set<const T*>>    grid_;

    /**
     * @brief Calcula las celdas de cuadrícula cubiertas por un rectángulo.
     *
     * @param rect Rectángulo en coordenadas de mundo.
     * @returns Vector de pares (x, y) de celdas superpuestas.
     */
    vector<pair<int, int>> get_covered_cells(const Rect& rect) const {
        int cx0 = rect.left   / width_;
        int cy0 = rect.top    / height_;
        int cx1 = rect.right  / width_;
        int cy1 = rect.bottom / height_;

        vector<pair<int, int>> cells;
        for (int cx = cx0; cx <= cx1; ++cx) {
            for (int cy = cy0; cy <= cy1; ++cy) {
                cells.push_back(make_pair(cx, cy));
            }
        }
        return cells;
    }

    /**
     * @brief Comprueba si dos rectángulos se intersectan.
     *
     * @param a Primer rectángulo.
     * @param b Segundo rectángulo.
     * @returns true si hay intersección, false en caso contrario.
     */
    static bool intersect(const Rect& a, const Rect& b) {
        return a.left <= b.right and b.left <= a.right and a.top <= b.bottom and b.top <= a.bottom;
    }


 public:
    // Constructor por defecto
    Finder() {}

    /**
     * @brief Registra un objeto en la cuadrícula.
     *
     * Almacena las celdas que cubre y añade el objeto a cada celda.
     *
     * @param t Puntero al objeto a añadir.
     */
    void add(const T *t) {
        Rect rect = t->get_rect();
        auto cells = get_covered_cells(rect);
        obj_[t] = cells;
        for (auto coord : cells)
            grid_[coord].insert(t);
    }

    /**
     * @brief Actualiza la posición de un objeto existente.
     *
     * Elimina la entrada antigua y vuelve a registrar en las nuevas celdas.
     *
     * @param t Puntero al objeto a actualizar.
     */
    void update(const T *t) {
        remove(t);
        add(t);
    }

    /**
     * @brief Elimina un objeto de la cuadrícula.
     *
     * Borra sus asociaciones de celdas y limpia celdas vacías.
     *
     * @param t Puntero al objeto a eliminar.
     */
    void remove(const T *t) {
        auto it = obj_.find(t);
        if (it != obj_.end()) {
            for (auto coord : it->second) {
                auto git = grid_.find(coord);
                if (git != grid_.end()) {
                    git->second.erase(t);
                    if (git->second.empty())
                        grid_.erase(git);
                }
            }
            obj_.erase(it);
        }
    }

    /**
     * @brief Retorna el conjunto de objetos cuyos rectángulos
     *        están total o parcialmente dentro de `qrect`.
     *
     * Complejidad O(log n) respecto al número de objetos.
     *
     * @param qrect Rectángulo de búsqueda.
     * @returns Conjunto de punteros a objetos T intersectados.
     */
    set<const T*> query(Rect qrect) const {
        set<const T*> result;
        auto cells = get_covered_cells(qrect);
        for (auto coord : cells) {
            auto git = grid_.find(coord);
            if (git != grid_.end()) {
                for (auto t : git->second) {
                    if (intersect(qrect, t->get_rect()))
                        result.insert(t);
                }
            }
        }
        return result;
    }
};


#endif