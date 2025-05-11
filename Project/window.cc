// <HUGE-WARNING>: This #include has to be first, don't move it!
#include "fenster.h"
// </HUGE-WARNING>

#include "window.hh"
using std::string;

namespace pro2 {

const int w = int(white);
const int c = 0xFF9800;
const int s = 0xFF5722;
const int b = 0x000000;
const int _ = -1;

static const std::vector<std::vector<int>> coin_texture_ = {
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

const std::vector<std::vector<std::vector<int>>> Window::digit_font_ = {{
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
const std::vector<std::vector<int>> Window::cross_ = {
    {w, _, _, _, w},
    {_, w, _, w, _},
    {_, _, w, _, _},
    {_, w, _, w, _},
    {w, _, _, _, w}
};

Window::Window(string title, int width, int height, int zoom)
    : fenster_{.title = title.c_str(), .width = width * zoom, .height = height * zoom},
      zoom_(zoom),
      pixels_size_(width * height * zoom * zoom)  //
{
    pixels_ = new uint32_t[width * height * zoom * zoom];
    fenster_.buf = pixels_;
    fenster_open(&fenster_);
    last_time_ = fenster_time();
}

void Window::update_camera_() {
    if (topleft_.x < topleft_target_.x) {
        topleft_.x += std::min(camera_speed_, topleft_target_.x - topleft_.x);
    } else if (topleft_.x > topleft_target_.x) {
        topleft_.x -= std::min(camera_speed_, topleft_.x - topleft_target_.x);
    }

    if (topleft_.y < topleft_target_.y) {
        topleft_.y += std::min(camera_speed_, topleft_target_.y - topleft_.y);
    } else if (topleft_.y > topleft_target_.y) {
        topleft_.y -= std::min(camera_speed_, topleft_.y - topleft_target_.y);
    }
}

bool Window::next_frame() {
    update_camera_();
    int wait = int(1000.0 / fps_) - (fenster_time() - last_time_);
    if (wait > 0) {
        fenster_sleep(wait);
    }
    last_time_ = fenster_time();
    frame_count_++;

    // Copy the keys array
    for (size_t i = 0; i < 256; i++) {
        last_keys_[i] = fenster_.keys[i];
    }
    last_mouse_ = fenster_.mouse;

    return fenster_loop(&fenster_) == 0;
}

void Window::clear(Color color) {
    for (size_t i = 0; i < pixels_size_; i++) {
        pixels_[i] = color;
    }
}

Pt Window::mouse_pos() const {
    const int width = fenster_.width / zoom_;
    const int height = fenster_.height / zoom_;

    int x = fenster_.x / zoom_;
    int y = fenster_.y / zoom_;
    if (x >= width) {
        x = width - 1;
    } else if (x < 0) {
        x = 0;
    }
    if (y >= height) {
        y = height - 1;
    } else if (y < 0) {
        y = 0;
    }

    return Pt{x + topleft_.x, y + topleft_.y};
}

void Window::set_pixel(Pt pt, Color color) {
    const Pt camera_pt = {pt.x - topleft_.x, pt.y - topleft_.y};
    for (int i = 0; i < zoom_; i++) {
        for (int j = 0; j < zoom_; j++) {
            const int _i = camera_pt.x * zoom_ + i;
            const int _j = camera_pt.y * zoom_ + j;
            if (_i >= 0 && _i < fenster_.width && _j >= 0 && _j < fenster_.height) {
                fenster_pixel(&fenster_, _i, _j) = color;
            }
        }
    }
}

void Window::draw_digit(int digit, int dx, int dy, const int font_h, const int font_w) {
    for (int y = 0; y < font_h; ++y) {
        for (int x = 0; x < font_w; ++x) {
            for (int j = 0; j < 2; ++j) {
                if (digit_font_[digit][y / 2][x / 2] >= 0)
                set_pixel({ dx + x, dy + y }, w);
            }
        }
    }
}

void Window::paint_interface(int& num_coins) {
    const int tex_h = (int)coin_texture_.size();
    const int tex_w = (int)coin_texture_[0].size();
    
    const Pt cam = camera_center();
    const Pt margin = {cam.x - (width() / 2) + 8, cam.y - (height() / 2) + 8};
    
    for (int i = 0; i < tex_h; ++i) {
        for (int j = 0; j < tex_w; ++j) {
            int color = coin_texture_[i][j];
            if (color >= 0) {
                set_pixel({ margin.x + j, margin.y + i }, color);
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
                set_pixel({ cx + x, dy + y + 2 }, w);
        }
    }
    
    
    draw_digit(tens, dx1, dy, font_h, font_w);
    draw_digit(units, dx2, dy, font_h, font_w);
}

}  // namespace pro2