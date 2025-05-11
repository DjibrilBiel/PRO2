#include "game.hh"
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150}),
      platforms_{
          Platform(100, 300, 200, 216),
          Platform(0, 200, 250, 266),
          Platform(250, 400, 150, 166),
      },
      blocks_{
          Block(0, 218),
          Block(0, 202),
      },
      coins_{
          Coin(250, 100),
          Coin(250, 82),
      },
      block_coins_{
          Block_Coin(64, 202),
      },
      finished_(false) {
    for (int i = 1; i < 20; i++) 
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 166));
    for (int i = 1; i < 60; i++) {
        coins_.push_back(Coin(250 + i * 12, 100));
        coins_.push_back(Coin(250 + i * 12, 82));
    }
    for(int i = 1; i < 4; ++i) {
        blocks_.push_back(Block(i * 16, 202));
    }
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
}

void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platforms_, blocks_, block_coins_, coins_, num_coins_taken_);
    /* for (Block& b : blocks_) {
        if (not b.is_broken())
            b.update(window, mario_);
    } */
}

void Game::update_camera(pro2::Window& window) {
    const Pt pos = mario_.pos();
    const Pt cam = window.camera_center();

    const int left = cam.x - window.width() / 4;
    const int right = cam.x + window.width() / 4;
    const int top = cam.y - window.height() / 4;
    const int bottom = cam.y + window.height() / 4;

    int dx = 0, dy = 0;
    if (pos.x > right) {
        dx = pos.x - right;
    } else if (pos.x < left) {
        dx = pos.x - left;
    }
    if (pos.y < top) {
        dy = pos.y - top;
    } else if (pos.y > bottom) {
        dy = pos.y - bottom;
    }

    window.move_camera({dx, dy});
}

void Game::update(pro2::Window& window) {
    process_keys(window);
    update_objects(window);
    update_camera(window);
}

void Game::paint(pro2::Window& window) {
    window.clear(sky_blue);

    for (const Platform& p : platforms_) {
        p.paint(window);
    }
    for (const Coin& c : coins_) {
        if (not c.is_taken())
            c.paint(window);
    }
    for (const Block& b : blocks_) {
        if (not b.is_broken())
            b.paint(window);
    }
    for (const Block_Coin& bc : block_coins_) {
        bc.paint(window);
    }
    mario_.paint(window);

    window.paint_interface(num_coins_taken_);
}