#ifndef BLOCK_HH
#define BLOCK_HH

#include "utils.hh"
#include <vector>

class Block {
 private:
    int left_, top_, right_, bottom_;

    bool broken_ = false;

    static const std::vector<std::vector<int>> block_texture_;

 public:
    Block() : left_(0), top_(0), right_(16), bottom_(16) {}

    Block(const Block& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    Block(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {} 

    Block(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    void paint(pro2::Window& window) const;

    bool is_broken() const;

    int left() const {
        return left_;
    }

    int top() const {
        return top_;
    }

    int right() const {
        return right_;
    }

    int bottom() const {
        return bottom_;
    }

    bool has_crossed_block_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    bool has_crossed_block_upwards(pro2::Pt plast, pro2::Pt pcurr) const;

    bool has_crossed_block_left_to_right(pro2::Pt plast, pro2::Pt pcurr) const;

    bool has_crossed_block_right_to_left(pro2::Pt plast, pro2::Pt pcurr) const;

    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif