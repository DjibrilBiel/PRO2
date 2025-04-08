#include <string>
#include <vector>
using namespace std;

#include "player.hh"


vector<string> winners(vector<Player>::iterator begin, vector<Player>::iterator end) {
   vector<string> w;
   vector<Player>::iterator it = begin;

   int s = 0;
   while (it != end) {
      Player p = *it;
      if (s < p.score) s = p.score;
      ++it;
   }

   it = begin;
   while (it != end) {
      Player p = *it;
      if (s == p.score) w.push_back(p.name);
      ++it;
   }

   return w;
}
