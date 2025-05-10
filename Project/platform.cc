#include "platform.hh"
using namespace std;

using pro2::Color;

const int c = 0xE85A07;
const int w = 0xF7D7B6;
const int b = 0x000000;

// clang-format off
const vector<vector<int>> Platform::platform_texture_ = {
    {c, w, w, w, w, c, c, w, w, w, w, w, w, w, w, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {w, b, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {c, b, b, b, b, c, w, c, c, c, c, c, c, c, c, b},
    {w, w, w, w, w, b, w, c, c, c, c, c, c, c, c, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {w, c, c, c, c, b, w, c, c, c, c, c, c, c, c, b},
    {c, c, c, c, c, b, b, b, c, c, c, c, c, c, b, w},
    {c, c, c, c, c, b, w, w, b, b, c, c, c, c, b, w},
    {c, c, c, c, c, b, w, c, w, w, b, b, b, b, w, c},
    {c, c, c, c, c, b, w, c, c, c, w, w, w, b, w, c},
    {c, c, c, c, b, b, w, c, c, c, c, c, c, b, w, c},
    {b, b, b, b, b, c, c, b, b, b, b, b, b, c, w, b},
};
// clang-format on

void Platform::paint(pro2::Window& window) const {
    const int xsz = platform_texture_.size();
    const int ysz = platform_texture_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j < right_; j++) {
            window.set_pixel({j, i}, platform_texture_[(i - top_ - 1) % xsz][(j - left_) % ysz]);
        }
    }
}

bool Platform::has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ <= plast.x && plast.x <= right_) && (left_ <= pcurr.x && pcurr.x <= right_) && (plast.y <= top_ && pcurr.y >= top_);
}

bool Platform::is_pt_inside(pro2::Pt pt) const {
	return left_ <= pt.x && pt.x <= right_ && top_ <= pt.y && pt.y <= bottom_;
}