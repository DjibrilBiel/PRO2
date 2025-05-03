#ifndef COIN_HH
#define COIN_HH

#include <vector>
#include "window.hh"
#include "utils.hh"

class Coin {
 private:
    pro2::Pt pos_;
    int numcoin_;
    bool horizontal_;

    static const std::vector<std::vector<int>> coin_texture_;

 public:
    Coin() : pos_({0,0}), numcoin_(1), horizontal_(true) {}

    Coin(const Coin& other) 
        : pos_(other.pos_), numcoin_(other.numcoin_), horizontal_(other.horizontal_) {}

    Coin(pro2::Pt pos, int numcoin, bool horizontal)
        : pos_(pos), numcoin_(numcoin), horizontal_(horizontal) {}

    void paint(pro2::Window& window) const;

};

#endif