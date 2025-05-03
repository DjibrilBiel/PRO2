#include "coin.hh"
using namespace std;

using pro2::Color;

const int c = 0xE49A39;
const int s = 0x974B1A;
const int b = 0x010101;
const int _ = 0x000000;

// clang-format off
const vector<vector<int>> Coin::coin_texture_ = {
    {_, _, c, c, c, c, b, b, _, _, _},
	{_, c, c, c, c, c, c, b, b, _, _},
	{_, c, c, s, s, c, c, b, b, _, _},
	{c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
	{c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
    {c, c, s, c, c, b, c, c, b, b, _},
    {_, c, c, b, b, c, c, b, b, _, _},
	{_, c, c, c, c, c, c, b, b, _, _},
	{_, _, c, c, c, c, b, b, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, _},
};
// clang-format on

void Coin::paint(pro2::Window& window) const {
    const int tex_h = (int)coin_texture_.size();
    const int tex_w = (int)coin_texture_[0].size();

    for (int k = 0; k < numcoin_; ++k) {
        int base_x = pos_.x + (horizontal_ ? k * tex_w : 0);
        int base_y = pos_.y + (horizontal_ ? 0 : k * tex_h);

        for (int i = 0; i < tex_h; ++i) {
            for (int j = 0; j < tex_w; ++j) {
                int color = coin_texture_[i][j];
                if (color != _) 
                    window.set_pixel({ base_x + j, base_y + i }, color);
            }
        }
    }
}