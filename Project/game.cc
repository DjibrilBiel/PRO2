#include "game.hh"
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150}),
      platforms_{
          Platform(0, 200, 250, 266),
          Platform(100, 300, 200, 216),
          Platform(250, 400, 150, 166),
      },
      blocks_{
          Block(0, 218),
          Block(0, 202),
          Block(150, 150),
      },
      coins_{
          Coin(250, 100),
          Coin(250, 82),
      },
      block_coins_{
          Block_Coin(64, 202),
          Block_Coin(200, 150),
      },
      finished_(false) {
    for (int i = 1; i < 1000; i++) 
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 166));
    for (int i = 1; i < 500; i++) {
        coins_.push_back(Coin(250 + i * 12, 100));
        coins_.push_back(Coin(250 + i * 12, 82));
    }
    for(int i = 1; i < 4; ++i) {
        blocks_.push_back(Block(i * 16, 202));
    }

    for (auto& p : platforms_)   platform_finder_.add(&p);
    for (auto& b : blocks_)      block_finder_.add(&b);
    for (auto& c : coins_)       coin_finder_.add(&c);
    for (auto& bc: block_coins_) block_coin_finder_.add(&bc);
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
}

void Game::update_objects(pro2::Window& window) {
    pro2::Rect view = window.get_viewport_rect();
    auto platform = platform_finder_.query(view);
    auto block = block_finder_.query(view);
    auto coin = coin_finder_.query(view);
    auto block_coin = block_coin_finder_.query(view);
    mario_.update(window, platform, block, block_coin, coin, num_coins_taken_);

    for (auto& bc : block_coins_) 
        bc.update_coin();
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

    pro2::Rect view = window.get_viewport_rect();
    auto platform_to_paint = platform_finder_.query(view);
    auto block_to_paint = block_finder_.query(view);
    auto coin_to_paint = coin_finder_.query(view);
    auto block_coin_to_paint = block_coin_finder_.query(view);

    for (auto p : platform_to_paint) {
        p->paint(window);
    }
    for (auto c : coin_to_paint) {
        if (not c->is_taken())
            c->paint(window);
    }
    for (auto b : block_to_paint) {
        if (not b->is_broken())
            b->paint(window);
    }
    for (auto bc : block_coin_to_paint) {
        bc->paint(window);
        bc->paint_coin(window);
    }
    mario_.paint(window);

    ccounter_.paint_interface(window, num_coins_taken_);
}