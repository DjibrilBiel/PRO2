#include "coin.hh"
using namespace std;

using pro2::Color;

const int c = 0xFF9800;
const int s = 0xFF5722;
const int g = 0x795548;
const int m = 0x3E2723;
const int w = 0x5D4037;
const int b = 0x000000;
const int _ = -1;

// clang-format off
const vector<vector<int>> Coin::coin_texture_0_ = {
    {_, _, c, c, c, c, b, b, _, _},
	{_, c, c, c, c, c, c, b, b, _},
	{_, c, c, s, s, c, c, b, b, _},
	{c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
	{c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
    {c, c, s, c, c, b, c, c, b, b},
    {_, c, c, b, b, c, c, b, b, _},
	{_, c, c, c, c, c, c, b, b, _},
	{_, _, c, c, c, c, b, b, _, _},
};

const vector<vector<int>> Coin::coin_texture_1_ = {
    {_, _, g, g, g, g, b, b, _, _},
	{_, g, g, g, g, g, g, b, b, _},
	{_, g, g, g, g, g, g, b, b, _},
	{g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
	{g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
    {g, g, g, g, g, b, g, g, b, b},
    {_, g, g, b, b, g, g, b, b, _},
	{_, g, g, g, g, g, g, b, b, _},
	{_, _, g, g, g, g, b, b, _, _},
};

const vector<vector<int>> Coin::coin_texture_2_ = {
    {_, _, m, m, m, m, b, b, _, _},
	{_, m, m, m, m, m, m, b, b, _},
	{_, m, m, w, w, m, m, b, b, _},
	{m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
	{m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
    {m, m, w, m, m, b, m, m, b, b},
    {_, m, m, b, b, m, m, b, b, _},
	{_, m, m, m, m, m, m, b, b, _},
	{_, _, m, m, m, m, b, b, _, _},
};
// clang-format on

void Coin::paint(pro2::Window& window) const {
    const int xsz = coin_texture_0_.size();
    const int ysz = coin_texture_0_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j < right_; j++) {
            static std::vector<std::vector<int>> actual_coin_texture;
            const int num_frame = (window.frame_count() % 50) / 10;
            if (num_frame == 0 or num_frame == 1)
                actual_coin_texture = coin_texture_0_;
            else if (num_frame == 3)
                actual_coin_texture = coin_texture_2_;
            else 
                actual_coin_texture = coin_texture_1_;

            int color = actual_coin_texture[(i - top_ - 1) % xsz][(j - left_) % ysz];
            if (color >= 0)
                window.set_pixel({j, i}, color);
        }
    }
}

bool Coin::is_taken() const {
    return taken_;
}

void Coin::taken(int& num_coins_taken) {
    if (not taken_) {
        taken_ = true;
        ++num_coins_taken;
    }
}

bool Coin::has_crossed_coin(pro2::Pt plast, pro2::Pt pcurr) const {
    bool from_top = (left_ - 6 <= plast.x && plast.x <= right_ + 6) && (left_ - 6 <= pcurr.x && pcurr.x <= right_ + 6) && (plast.y <= top_ && pcurr.y >= top_);
    bool from_bottom = (left_ - 6 <= plast.x && plast.x <= right_ + 6) && (left_ - 6 <= pcurr.x && pcurr.x <= right_ + 6) && (plast.y >= bottom_ + 15 && pcurr.y <= bottom_ + 15);
    bool from_left = plast.x <= left_ - 6 && pcurr.x >= left_ - 6 && ((plast.y - 1 >= top_ || pcurr.y - 1 >= top_) && (plast.y <= bottom_ + 15 || pcurr.y <= bottom_ + 15));
    bool from_right = plast.x >= right_ + 6 && pcurr.x <= right_ + 6 && ((plast.y - 1 >= top_ || pcurr.y - 1 >= top_) && (plast.y <= bottom_ + 15 || pcurr.y <= bottom_ + 15));
    return from_top or from_bottom or from_left or from_right;
}