#include "game.hh"
#include "utils.hh"
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150}, Keys::Up, Keys::Left, Keys::Right),
      mario2_({width / 2 - 30, 150}, 'W', 'A', 'D'),
      platforms_{
          Platform(100, 300, 200, 211),
          Platform(0, 200, 250, 261),
          Platform(250, 400, 150, 161),
      },
      finished_(false) {
    for (int i = 1; i < 20; i++) {
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    }
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
    if (window.was_key_pressed('P')) {
        if (paused_) paused_ = false;
        else paused_ = true;
        return;
    } 
}

void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platforms_);
    mario2_.update(window, platforms_);
}

void Game::update_camera(pro2::Window& window) {
    const Pt pos = mario_.pos();
    const Pt cam = window.camera_center();

    /* const int left = cam.x - window.width() / 4;
    const int right = cam.x + window.width() / 4;
    const int top = cam.y - window.height() / 4;
    const int bottom = cam.y + window.height() / 4; */

    /* int dx = 0, dy = 0;
    if (pos.x > right) {
        dx = pos.x - right;
    } else if (pos.x < left) {
        dx = pos.x - left;
    }
    if (pos.y < top) {
        dy = pos.y - top;
    } else if (pos.y > bottom) {
        dy = pos.y - bottom;
    } */
    int dx = pos.x - cam.x;
    int dy = pos.y - cam.y;

    window.move_camera({dx, dy});
}

void Game::update(pro2::Window& window) {
    process_keys(window);
    if (not paused_) {
        update_objects(window);
        update_camera(window);
    }
}

void Game::paint(pro2::Window& window) {
    window.clear(sky_blue);

    const Rect cam = window.camera_rect();
    const int w = window.width();
    const int h = window.height();

    if (pampallugues_) {
        paint_rect(window, {cam.left + 410, cam.top + 20, cam.right - 20, cam.bottom - 250}, yellow);
        pampallugues_ = false;
    } else pampallugues_ = true;
    
    for (const Platform& p : platforms_) {
        p.paint(window);
    }

    paint_hline(window, cam.left, cam.right, cam.top, black);
    paint_hline(window, cam.left, cam.right, cam.bottom - 1, black);
    paint_vline(window, cam.left, cam.top, cam.bottom, black);
    paint_vline(window, cam.right - 1, cam.top, cam.bottom, black);

    mario_.paint(window);
    mario2_.paint(window);
}