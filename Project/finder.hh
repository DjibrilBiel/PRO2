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
    const int width_  = 960;
    const int height_ = 640;

    // Mapa que relaciona un objeto con las coordenadas de las celdas de la cuadrícula que ocupa
    map<const T*, vector<pair<int, int>>> obj_;
    // Coordenadas de celda de la cuadrícula a conjunto de objetos
    map<pair<int, int>, set<const T*>>    grid_;

    // Obtiene la lista de coordenadas de celdas de la cuadrícula solapadas por un rectángulo
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

    static bool intersect(const Rect& a, const Rect& b) {
        return a.left <= b.right and b.left <= a.right and a.top <= b.bottom and b.top <= a.bottom;
    }


 public:
    Finder() {}

    void add(const T *t) {
        Rect rect = t->get_rect();
        auto cells = get_covered_cells(rect);
        obj_[t] = cells;
        for (auto coord : cells)
            grid_[coord].insert(t);
    }

    void update(const T *t) {
        remove(t);
        add(t);
    }

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
     * @brief Retorna el conjunt d'objectes amb rectangles 
     *        total o parcialment dins de `rect`.
     *
     * Si el nombre de rectangles del contenidor és `n`, el 
     * cost de l'algorisme ha de ser O(log n).
     *
     * @param rect El rectangle de cerca
     *
     * @returns Un conjunt de punters a objectes que tenen un 
     *          rectangle parcial o totalment dins de `rect`
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