#ifndef OBJECT_HH
#define OBJECT_HH

#include "geometry.hh"

class TestObject {
    pro2::Rect rect_;
public:
    explicit TestObject(pro2::Rect rect) : rect_(rect) {}

    pro2::Rect get_rect() const { return rect_; }
};

#endif