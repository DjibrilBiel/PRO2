#ifndef BLOCK_COIN_HH
#define BLOCK_COIN_HH

#include "utils.hh"
#include <vector>
using namespace std;

class Block_Coin {
 private:
    int left_, top_, right_, bottom_;

    bool hit_ = false;

    static const vector<vector<int>> block_hit_texture_, block_texture_;

 public:
    Block_Coin() : left_(0), top_(0), right_(16), bottom_(16) {}

    Block_Coin(const Block_Coin& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    Block_Coin(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {} 

    Block_Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    void paint(pro2::Window& window) const;

    bool is_hit() const;

    void hit(int& num_coins);

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
};

#endif