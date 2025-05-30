#include "block.hh"
using namespace std;

const int c = 0xE85A07;
const int w = 0xF7D7B6;
const int b = 0x000000;

// clang-format off
const vector<vector<int>> Block::block_texture_ = {
    {w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w},
    {c, c, c, c, c, c, c, b, c, c, c, c, c, c, c, b},
    {c, c, c, c, c, c, c, b, c, c, c, c, c, c, c, b},
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
    {c, c, c, c, c, c, c, b, c, c, c, c, c, c, c, b},
    {c, c, c, c, c, c, c, b, c, c, c, c, c, c, c, b},
    {c, c, c, c, c, c, c, b, c, c, c, c, c, c, c, b},
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {c, c, c, b, c, c, c, c, c, c, c, b, c, c, c, c},
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
};
// clang-format on

void Block::paint(pro2::Window& window) const {
    const int xsz = block_texture_.size();
    const int ysz = block_texture_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j < right_; j++) {
            int color = block_texture_[(i - top_ - 1) % xsz][(j - left_) % ysz];
            if (color >= 0)
                window.set_pixel({j, i}, color);
        }
    }
}

bool Block::is_broken() const {
    return broken_;
}

void Block::broken() {
    broken_ = true;
}

bool Block::has_crossed_block_downwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ + pmod.left + 1 <= plast.x && plast.x <= right_ + pmod.right - 1) && (left_ + pmod.left + 1 <= pcurr.x && pcurr.x <= right_ + pmod.right - 1) && (plast.y <= top_ + pmod.top && pcurr.y >= top_ + pmod.top);
}

bool Block::has_crossed_block_upwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ + pmod.left + 1 <= plast.x && plast.x <= right_ + pmod.right - 1) && (left_ + pmod.left + 1 <= pcurr.x && pcurr.x <= right_ + pmod.right - 1) && (plast.y >= bottom_ + pmod.bottom && pcurr.y <= bottom_ + pmod.bottom);
}

bool Block::has_crossed_block_left_to_right(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return plast.x <= left_ + pmod.left && pcurr.x >= left_ + pmod.left && ((plast.y - 2 >= top_ + pmod.top || pcurr.y - 2 >= top_ + pmod.top) && (plast.y <= bottom_ + pmod.bottom || pcurr.y <= bottom_ + pmod.bottom));
}

bool Block::has_crossed_block_right_to_left(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return plast.x >= right_ + pmod.right && pcurr.x <= right_ + pmod.right && ((plast.y - 2 >= top_ + pmod.top || pcurr.y - 2 >= top_ + pmod.top) && (plast.y <= bottom_ + pmod.bottom || pcurr.y <= bottom_ + pmod.bottom));
}