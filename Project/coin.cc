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
	{_, _, m, m, m, m, b, b, _, _}
};
// clang-format on

void Coin::paint(pro2::Window& window) const {
    const int tex_h = 14;
    const int tex_w = 10;
    int base_x = posX_ + tex_w;
    int base_y = posY_ + tex_h;

    for (int i = 0; i < tex_h; ++i) {
        for (int j = 0; j < tex_w; ++j) {
            static std::vector<std::vector<int>> actual_coin_texture;
            const int num_frame = (window.frame_count() % 50) / 10;
            if (num_frame == 0 or num_frame == 1)
                actual_coin_texture = coin_texture_0_;
            else if (num_frame == 3)
                actual_coin_texture = coin_texture_2_;
            else 
                actual_coin_texture = coin_texture_1_;

            int color = actual_coin_texture[i][j];
            if (color >= 0)
                window.set_pixel({ base_x + j, base_y + i }, color);
        }
    }
}

bool Coin::is_taken() const {
    return taken_;
}

void Coin::update(pro2::Window& window, Mario& mario, int& num_coins_taken) {
    const int tex_h = 10;
    const int tex_w = 14;
    int c_left   = posX_;
    int c_right  = posX_ + tex_w - 1;
    int c_top    = posY_;
    int c_bottom = posY_ + tex_h - 1;

    pro2::Pt mpos = mario.pos();
    int m_left   = mpos.x - 13;
    int m_right  = mpos.x - 5;
    int m_top    = mpos.y - 33;
    int m_bottom = mpos.y - 25;

    if ((m_right >= c_left) && (m_left <= c_right) && (m_bottom >= c_top) && (m_top <= c_bottom)) {
        taken_ = true;
        ++num_coins_taken;
    }
}