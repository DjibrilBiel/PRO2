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
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b}
};
// clang-format on

void Block::paint(pro2::Window& window) const {
    const int tex_h = 16;
    const int tex_w = 16;
    int base_x = posX_ + tex_w;
    int base_y = posY_ + tex_h;

    for (int i = 0; i < tex_h; ++i) {
        for (int j = 0; j < tex_w; ++j) {
            int color = block_texture_[i][j];
            if (color >= 0)
                window.set_pixel({ base_x + j, base_y + i }, color);
        }
    }
}

bool Block::is_broken() const {
    return broken_;
}

bool Block::has_crossed_block_downwards(pro2::Pt plast, pro2::Pt pcurr) const {
    return (body_.left <= plast.x && plast.x <= body_.right) && (body_.left <= pcurr.x && pcurr.x <= body_.right) && (plast.y <= body_.top && pcurr.y >= body_.top);
}

/* bool Block::has_crossed_block_upwards(pro2::Pt plast, pro2::Pt pcurr) const {
    int left = posX_;
    int right = posX_ + 16;
    int bottom = posY_;
    
    return (left <= plast.x && plast.x <= right) && (left <= pcurr.x && pcurr.x <= right) && (plast.y >= bottom && pcurr.y <= bottom);
} */