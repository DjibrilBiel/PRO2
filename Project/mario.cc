#include "mario.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

const int _ = -1;
const int r = pro2::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = pro2::yellow;
const int h = pro2::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// clang-format off
const vector<vector<int>> Mario::mario_sprite_normal_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};

const vector<vector<int>> Mario::mario_sprite_big_ = {
    {_, _, _, _, _, r, r, r, r, r, _, _, _, _, _, _},
    {_, _, _, r, r, r, r, r, r, y, _, _, _, _, _, _},
    {_, _, r, r, r, r, r, r, y, y, _, _, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, r, r, _, _, _},
    {_, _, h, h, h, s, s, h, s, s, s, _, _, _, _, _},
    {_, h, s, s, h, s, s, h, h, s, s, s, s, _, _, _},
    {_, h, s, s, h, h, s, s, s, s, s, s, s, s, _, _},
    {h, h, s, s, h, h, s, s, s, h, s, s, s, s, _, _},
    {h, h, s, s, s, s, s, h, h, h, h, h, h, _, _, _},
    {h, h, h, h, s, s, s, s, h, h, h, h, h, _, _, _},
    {_, _, h, h, h, s, s, s, s, s, s, s, _, _, _, _},
    {_, _, _, _, b, s, s, s, s, s, r, _, _, _, _, _},
    {_, _, _, _, r, b, r, r, r, r, b, r, _, _, _, _},
    {_, _, _, r, r, b, r, r, r, r, b, r, r, _, _, _},
    {_, _, r, r, r, b, r, r, r, r, b, r, r, r, _, _},
    {_, r, r, r, r, b, r, r, r, r, b, r, r, r, r, _},
    {_, r, r, r, r, b, r, r, r, r, b, r, r, r, r, _},
    {r, r, r, r, b, b, r, r, r, r, b, b, r, r, r, r},
    {r, r, r, r, b, b, r, r, r, r, b, b, r, r, r, r},
    {r, r, r, r, b, b, b, b, b, b, b, b, r, r, r, r},
    {r, r, r, r, b, y, b, b, b, b, y, b, r, r, r, r},
    {g, g, g, g, b, b, b, b, b, b, b, b, g, g, g, g},
    {g, g, g, g, b, b, b, b, b, b, b, b, g, g, g, g},
    {_, g, g, g, b, b, b, b, b, b, b, b, g, g, g, _},
    {_, g, g, b, b, b, b, b, b, b, b, b, b, g, g, _},
    {_, _, b, b, b, b, b, b, b, b, b, b, b, b, _, _},
    {_, b, b, b, b, b, b, _, _, b, b, b, b, b, b, _},
    {_, b, b, b, b, b, _, _, _, _, b, b, b, b, b, _},
    {_, b, b, b, b, b, _, _, _, _, b, b, b, b, b, _},
    {_, _, w, w, w, w, _, _, _, _, w, w, w, w, _, _},
    {w, w, w, w, w, w, _, _, _, _, w, w, w, w, w, w},
    {w, w, w, w, w, w, _, _, _, _, w, w, w, w, w, w},
};
// clang-format on

void Mario::paint(pro2::Window& window) const {
    
    if (status_mario_) {
        const Pt top_left = {pos_.x - 8, pos_.y - 31};
        paint_sprite(window, top_left, mario_sprite_big_, looking_left_);
    } else {
        const Pt top_left = {pos_.x - 6, pos_.y - 15};
        paint_sprite(window, top_left, mario_sprite_normal_, looking_left_);
    }
}

void Mario::apply_physics_() {
    if (grounded_) {
        speed_.y = 0;
        accel_.y = 0;
    }

    // Always falling to check if we aren't grounded
    // If we are, we will return to the same spot

    const int gravity = 1;  // gravity = 1 pixel / frame_time^2
    speed_.y += gravity;

    if (accel_time_ > 0) {
        speed_.y += accel_.y;
        accel_time_--;
    }

    pos_.x += speed_.x;
    pos_.y += speed_.y;
}

void Mario::jump() {
    if (grounded_) {
        accel_.y = -6;
        grounded_ = false;
        accel_time_ = 2;
    }
}

void Mario::update(pro2::Window& window, const set<Platform*>& platforms, set<Block*>& blocks, set<Block_Coin*>& block_coins, set<Coin*>& coins, int& num_coins) {
    last_pos_ = pos_;
    if (window.is_key_down(Keys::Space)) {
        jump();
    }

    // Velocitat horitzontal
    speed_.x = 0; 
    if (window.is_key_down(Keys::Left)) {
        speed_.x = -4;
    } else if (window.is_key_down(Keys::Right)) {
        speed_.x = 4;
    }
    if (speed_.x != 0) {
        looking_left_ = speed_.x < 0;
    }

    // Apply acceleration and speed
    apply_physics_();

    // Check position
    set_grounded(false);

    Rect pos_mod = get_rect_modifiers();

    for (auto& platform : platforms) {
        if (platform->has_crossed_floor_downwards(last_pos_, pos_)) {
            set_grounded(true);
            set_y(platform->top());
        }
    }
    for (auto& block_coin : block_coins) {
        if (block_coin->has_crossed_block_downwards(pos_mod, last_pos_, pos_)) {
            set_grounded(true);
            set_y(block_coin->top());
        } else if (block_coin->has_crossed_block_upwards(pos_mod, last_pos_, pos_)) {
            block_coin->hit(num_coins);
            speed_.y = 0;
            set_y(block_coin->bottom() + pos_mod.bottom + 1);
        } else if (block_coin->has_crossed_block_left_to_right(pos_mod, last_pos_, pos_)) {
            speed_.x = 0;
            set_x(block_coin->left() + pos_mod.left);
        } else if (block_coin->has_crossed_block_right_to_left(pos_mod, last_pos_, pos_)) {
            speed_.x = 0;
            set_x(block_coin->right() + pos_mod.right);
        }
    }
    for (auto& block : blocks) {
        if (block->is_broken()) continue;
        if (block->has_crossed_block_downwards(pos_mod, last_pos_, pos_)) {
            set_grounded(true);
            set_y(block->top());
        } else if (block->has_crossed_block_upwards(pos_mod, last_pos_, pos_)) {
            speed_.y = 0;
            set_y(block->bottom() + pos_mod.bottom + 1);
            if (status_mario_) block->broken();
        } else if (block->has_crossed_block_left_to_right(pos_mod, last_pos_, pos_)) {
            speed_.x = 0;
            set_x(block->left() + pos_mod.left);
        } else if (block->has_crossed_block_right_to_left(pos_mod, last_pos_, pos_)) {
            speed_.x = 0;
            set_x(block->right() + pos_mod.right);
        }
    }
    for (auto& coin : coins) {
        if (coin->has_crossed_coin(pos_mod, last_pos_, pos_)) {
            coin->taken(num_coins);
        }
    }

    if (window.was_key_pressed('M')) {
        status_mario_ = not status_mario_;
    }
}