#ifndef BLOCK_HH
#define BLOCK_HH

#include "utils.hh"
#include <vector>

class Block {
 private:
    int posX_, posY_;
    pro2::Rect body_;

    bool broken_ = false;

    static const std::vector<std::vector<int>> block_texture_;

 public:
    Block() : posX_(0), posY_(0), body_({0, 0, 16, 16}) {}

    Block(const Block& other) : posX_(other.posX_), posY_(other.posY_) {
        body_ = {posX_, posY_, posX_ + 16, posX_ + 16};
    }

    Block(pro2::Pt pos) : posX_(pos.x), posY_(pos.y) {
        body_ = {posX_, posY_, posX_ + 16, posX_ + 16};
    }

    Block(int posx, int posy)
        : posX_(posx), posY_(posy), body_({posx, posy, posx + 16, posy + 16}) {}

    void paint(pro2::Window& window) const;

    bool is_broken() const;

    int top() const {
        return body_.top;
    }

    int bottom() const {
        return body_.bottom;
    }

    bool has_crossed_block_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /* bool has_crossed_block_upwards(pro2::Pt plast, pro2::Pt pcurr) const; */
};

#endif