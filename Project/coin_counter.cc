#include "coin_counter.hh"

const int w = int(pro2::white);
const int c = 0xFF9800;
const int s = 0xFF5722;
const int b = 0x000000;
const int _ = -1;

const std::vector<std::vector<int>> Coin_Counter::coin_texture_ = {
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

const std::vector<std::vector<std::vector<int>>> digit_font_ = {{
  // 0
  {{{_, _, w, w, w, _, _},
    {_, w, _, _, w, w, _},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, _, _, w, _},
    {_, _, w, w, w, _, _}}},
  // 1
  {{{_, _, _, w, w, _, _},
    {_, _, w, w, w, _, _},
    {_, _, _, w, w, _, _},
    {_, _, _, w, w, _, _},
    {_, _, _, w, w, _, _},
    {_, _, _, w, w, _, _},
    {_, w, w, w, w, w, w}}},
  // 2
  {{{_, w, w, w, w, w, _},
    {w, w, _, _, _, w, w},
    {_, _, _, _, w, w, w},
    {_, _, w, w, w, w, _},
    {_, w, w, w, w, _, _},
    {w, w, w, _, _, _, _},
    {w, w, w, w, w, w, w}}},
  // 3
  {{{_, w, w, w, w, w, w},
    {_, _, _, _, w, w, _},
    {_, _, _, w, w, _, _},
    {_, _, w, w, w, w, _},
    {_, _, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, _}}},
  // 4
  {{{_, _, _, w, w, w, _},
    {_, _, w, w, w, w, _},
    {_, w, w, _, w, w, _},
    {w, w, _, _, w, w, _},
    {w, w, w, w, w, w, w},
    {_, _, _, _, w, w, _},
    {_, _, _, _, w, w, _}}},
  // 5
  {{{w, w, w, w, w, w, _},
    {w, w, _, _, _, _, _},
    {w, w, w, w, w, w, _},
    {_, _, _, _, _, w, w},
    {_, _, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, _}}},
  // 6
  {{{_, _, w, w, w, w, _},
    {_, w, w, _, _, _, _},
    {w, w, _, _, _, _, _},
    {w, w, w, w, w, w, _},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, _}}},
  // 7
  {{{w, w, w, w, w, w, w},
    {w, w, _, _, _, w, w},
    {_, _, _, _, w, w, _},
    {_, _, _, w, w, _, _},
    {_, _, w, w, _, _, _},
    {_, _, w, w, _, _, _},
    {_, _, w, w, _, _, _}}},
  // 8
  {{{_, w, w, w, w, w, _},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, _},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, _}}},
  // 9
  {{{_, w, w, w, w, w, _},
    {w, w, _, _, _, w, w},
    {w, w, _, _, _, w, w},
    {_, w, w, w, w, w, w},
    {_, _, _, _, _, w, w},
    {_, _, _, _, w, w, _},
    {_, w, w, w, w, _, _}}}
}};
const std::vector<std::vector<int>> cross_ = {
    {w, _, _, _, w},
    {_, w, _, w, _},
    {_, _, w, _, _},
    {_, w, _, w, _},
    {w, _, _, _, w}
};

void Coin_Counter::draw_digit(pro2::Window& window, int digit, int dx, int dy, const int font_h, const int font_w) {
    for (int y = 0; y < font_h; ++y) {
        for (int x = 0; x < font_w; ++x) {
            for (int j = 0; j < 2; ++j) {
                if (digit_font_[digit][y / 2][x / 2] >= 0)
                    window.set_pixel({ dx + x, dy + y }, w);
            }
        }
    }
}

void Coin_Counter::paint_interface(pro2::Window& window, int& num_coins) {
    const int tex_h = (int)coin_texture_.size();
    const int tex_w = (int)coin_texture_[0].size();
    
    const pro2::Pt cam = window.camera_center();
    const pro2::Pt margin = {cam.x - (window.width() / 2) + 8, cam.y - (window.height() / 2) + 8};
    
    for (int i = 0; i < tex_h; ++i) {
        for (int j = 0; j < tex_w; ++j) {
            int color = coin_texture_[i][j];
            if (color >= 0) {
                window.set_pixel({ margin.x + j, margin.y + i }, color);
            }
        }
    }


    int clamped;
    if (num_coins < 100){
        clamped = num_coins;
    } else {
        num_coins -= 100;
        clamped = num_coins;
    }
    int tens = clamped / 10;
    int units = clamped % 10;

    const int font_h = (int)digit_font_[0].size() * 2;
    const int font_w = (int)digit_font_[0][0].size() * 2;
    const int spacing = 2;

    const int cross_h = (int)cross_.size() * 2;
    const int cross_w = (int)cross_[0].size() * 2;

    int cx = margin.x + tex_w + spacing * 2;
    int dx1 = cx + cross_w + spacing * 2;
    int dx2 = dx1 + font_w + spacing;
    int dy = margin.y;


    for (int y = 0; y < cross_h; ++y) {
        for (int x = 0; x < cross_w; ++x) {
            if (cross_[y / 2][x / 2] >= 0)
                window.set_pixel({ cx + x, dy + y + 2 }, w);
        }
    }
    
    
    draw_digit(window, tens, dx1, dy, font_h, font_w);
    draw_digit(window, units, dx2, dy, font_h, font_w);
}