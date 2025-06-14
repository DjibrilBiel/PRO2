#include "block_coin.hh"

const int c = 0xE85A07;
const int w = 0xF7D7B6;
const int b = 0x000000;
const int _ = -1;

// clang-format off
const std::vector<std::vector<int>> Block_Coin::block_texture_ = {
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

const std::vector<std::vector<int>> Block_Coin::block_hit_texture_ = {
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, b, c, c, c, c, c, c, c, c, c, c, b, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, c, b, c, c, c, c, c, c, c, c, c, c, b, c, b},
    {b, c, c, c, c, c, c, c, c, c, c, c, c, c, c, b},
    {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
};

const int cc = 0xFF9800;
const int cs = 0xFF5722;
const int cw = 0xFFFFFF;

const std::vector<std::vector<int>> Block_Coin::coin_from_block_0_ = {
    { _, _, _,cc,cs, _, _, _},
    { _, _, _,cc,cs, _, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cw,cs,cs,cs, _, _},
    { _, _,cw,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _,cc,cs,cs,cs, _, _},
    { _, _, _,cc,cs, _, _, _},
    { _, _, _,cc,cs, _, _, _}
};

const std::vector<std::vector<int>> Block_Coin::coin_from_block_1_ = {
    { _, _, _,cc,cc, _, _, _},
    { _, _,cc,cc,cc,cc, _, _},
    { _,cc,cc,cc,cc,cc,cc, _},
    { _,cc,cc,cw,cs,cc,cc, _},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    {cc,cc,cw,cc,cc,cs,cc,cc},
    { _,cc,cc,cw,cs,cc,cc, _},
    { _,cc,cc,cc,cc,cc,cc, _},
    { _, _,cc,cc,cc,cc, _, _},
    { _, _, _,cc,cc, _, _, _}
};

const std::vector<std::vector<int>> Block_Coin::coin_from_block_2_ = {
    { _, _, _,cw,cs, _, _, _},
    { _, _, _,cw,cs, _, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _,cw,cw,cw,cs, _, _},
    { _, _, _,cw,cs, _, _, _},
    { _, _, _,cw,cs, _, _, _}
};

const std::vector<std::vector<int>> Block_Coin::coin_from_block_3_ = {
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cw, _, _, _},
    { _, _, _, _,cw, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _},
    { _, _, _, _,cc, _, _, _}
};

void Block_Coin::paint(pro2::Window& window) const {
    const int xsz = block_texture_.size();
    const int ysz = block_texture_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j < right_; j++) {
            int color;
            if (not hit_) color = block_texture_[(i - top_ - 1) % xsz][(j - left_) % ysz];
            else color = block_hit_texture_[(i - top_ - 1) % xsz][(j - left_) % ysz];
            if (color >= 0)
                window.set_pixel({j, i}, color);
        }
    }
}

bool Block_Coin::is_hit() const {
    return hit_;
}

void Block_Coin::hit(int& num_coins) { 
    if (not hit_) {
        hit_ = true;
        ++num_coins;
        
        // Animación Moneda
        show_coin_ = 79;
    }
}

void Block_Coin::update_coin() {
    if (show_coin_ > 0) {
        --show_coin_;
    }
}

void Block_Coin::paint_coin(pro2::Window& window) const {
    if (show_coin_ > 0) {
        const int xsz = coin_from_block_0_.size();
        const int ysz = coin_from_block_0_[0].size();
        for (int i = 0; i <= xsz; i++) {
            for (int j = 0; j < ysz; j++) {
                static std::vector<std::vector<int>> actual_coin_texture;
                const int num_frame = (window.frame_count() % 20) / 5;
                if (num_frame == 0) {
                    actual_coin_texture = coin_from_block_0_;
                } else if (num_frame == 1) {
                    actual_coin_texture = coin_from_block_1_;
                } else if (num_frame == 2) {
                    actual_coin_texture = coin_from_block_2_;
                } else {
                    actual_coin_texture = coin_from_block_3_;
                }
                int color = actual_coin_texture[i % xsz][j % ysz];
                if (color >= 0)
                    window.set_pixel({j + left_ + 4, i + top_ - 20}, color);
            }
        }
    }
}

bool Block_Coin::has_crossed_block_downwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ + pmod.left + 1 <= plast.x && plast.x <= right_ + pmod.right - 1) && (left_ + pmod.left + 1 <= pcurr.x && pcurr.x <= right_ + pmod.right - 1) && (plast.y <= top_ + pmod.top && pcurr.y >= top_ + pmod.top);
}

bool Block_Coin::has_crossed_block_upwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ + pmod.left + 1 <= plast.x && plast.x <= right_ + pmod.right - 1) && (left_ + pmod.left + 1 <= pcurr.x && pcurr.x <= right_ + pmod.right - 1) && (plast.y >= bottom_ + pmod.bottom && pcurr.y <= bottom_ + pmod.bottom);
}

bool Block_Coin::has_crossed_block_left_to_right(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return plast.x <= left_ + pmod.left && pcurr.x >= left_ + pmod.left && ((plast.y - 2 >= top_ + pmod.top || pcurr.y - 2 >= top_ + pmod.top) && (plast.y <= bottom_ + pmod.bottom || pcurr.y <= bottom_ + pmod.bottom));
}

bool Block_Coin::has_crossed_block_right_to_left(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const {
    return plast.x >= right_ + pmod.right && pcurr.x <= right_ + pmod.right && ((plast.y - 2 >= top_ + pmod.top || pcurr.y - 2 >= top_ + pmod.top) && (plast.y <= bottom_ + pmod.bottom || pcurr.y <= bottom_ + pmod.bottom));
}