#ifndef COIN_HH
#define COIN_HH

#include <vector>
#include "mario.hh"
#include "window.hh"
#include "utils.hh"

class Coin {
 private:
    int posX_, posY_;

    bool taken_;

    static const std::vector<std::vector<int>> coin_texture_0_, coin_texture_1_, coin_texture_2_;

 public:
    Coin() : posX_(0), posY_(0), taken_(false) {}

    Coin(const Coin& other) : posX_(other.posX_), posY_(other.posY_), taken_(false) {}

    Coin(pro2::Pt pos) : posX_(pos.x), posY_(pos.y), taken_(false) {}

    Coin(int posx, int posy) : posX_(posx), posY_(posy), taken_(false) {}

    void paint(pro2::Window& window) const;

    bool is_taken() const;

    void update(pro2::Window& window, Mario& mario, int& num_coins_taken);
};

#endif