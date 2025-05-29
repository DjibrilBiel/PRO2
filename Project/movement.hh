#ifndef MOVEMENT_HH
#define MOVEMENT_HH

#include "window.hh"
#include "mario.hh"
#include "finder.hh"
using namespace pro2;

/**
 * @brief Classe de moviment genèrica per a objectes o enemics.
 * @tparam T Tipus d'objecte que ha d'exposar get_rect() i opcionalment
 *           onTouchMario() / onBounce().
 */
template <typename T>
class Movement {
 public:
    Movement(const T* obj, Pt p, int v) : obj_(obj), pos_(p), vel_({v, 0}) {}

    void update(const Mario& mario, const set<Finder<const T*>>& finder_set) {
       obj_->pos.x += vel_.x;
       obj_->pos.y += vel_.y;

       for (finder_obj : finder_set) {
          auto hits = finder_obj.query(obj_->get_rect());
          for (auto* w : hits) {
             if (w != obj_) {
                if (isSolid(w)) {
                   obj_->pos.x -= vel_.x * 2;
                   vel_.x = -vel_.x;
                   break;
                }
             }
          }
       }

       bool inter = intersect(obj_->get_rect(), mario.get_rect())
       if (not touched_mario_ and inter) {
          touched_mario_ = true;
          obj_->onTouchMario();
       } else if (touched_mario_ and not inter) {
          touched_mario_ = false;
          obj_->onTouchMario();
       }
    }

    bool touchedMario() const {return touched_mario_}

    void setVelocity(int vx, int vy) {
       vel_.x = vx;
       vel_.y = vy;
    }

 private:
    const T* obj_;
    Pt pos_, vel_;
    bool touched_mario_ = false;
};

#endif