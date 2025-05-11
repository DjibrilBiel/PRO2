#ifndef COIN_HH
#define COIN_HH

#include <vector>
#include "utils.hh"

class Coin {
 private:
    int left_, top_, right_, bottom_;

    bool taken_ = false;

    static const std::vector<std::vector<int>> coin_texture_0_, coin_texture_1_, coin_texture_2_;

 public:
    Coin() : left_(0), top_(0), right_(10), bottom_(14) {}

    Coin(const Coin& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    Coin(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 10), bottom_(pos.y + 14) {} 

    Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 10), bottom_(posy + 14) {}

    void paint(pro2::Window& window) const;

    bool is_taken() const;

    void taken(int& num_coins_taken);

    bool has_crossed_coin(pro2::Pt plast, pro2::Pt pcurr) const;
};

#endif