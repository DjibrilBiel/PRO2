#ifndef FINDER_HH
#define FINDER_HH

#include "window.hh"
using namespace pro2;

#include <set>
#include <map>
using namespace std;

template <typename T>
class Finder {
    struct Entry {
        int left;
        const T* pointer;

        bool operator<(Entry const& obj) const {
            if (left != obj.left)
                return left < obj.left;
            return pointer < obj.pointer;
        }
    };

    set<Entry> index_;
    map<const T*, Entry> search_;
    
 public:
    Finder() {}

    void add(const T *t) {
        assert(t);
        Rect r = t->get_rect();
        Entry e = {r.left, t};
        auto it = index_.insert(e).first;
        search_[t] = *it;
    }

    void remove(const T *t) {
        auto it = search_.find(t);
        if (it != search_.end()) {
            index_.erase(it->second);
            search_.erase(it);
        }
    }

    void update(const T *t) {
        remove(t);
        add(t);
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
    set<const T*> query(Rect rect) const {
        set<const T*> result;

        for (auto const& e : index_) {

            if (e.left > rect.right) 
                break;
                
            Rect r = e.pointer->get_rect();
            if (r.right >= rect.left and r.bottom >= rect.top and r.top <= rect.bottom)
                result.insert(e.pointer);
        }

        return result;
    }
};


#endif