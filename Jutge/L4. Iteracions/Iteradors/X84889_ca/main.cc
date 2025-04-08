
#include <iostream>
#include <vector>
using namespace std;

#include "player.hh"

vector<string> winners(vector<Player>::iterator ini, vector<Player>::iterator fin);

int main() {
	Player p;
	vector<Player> v;
	while (cin >> p.name >> p.score) {
		v.push_back(p);
	}
	vector<string> w = winners(v.begin(), v.end());
	for (int i = 0; i < w.size(); i++) {
		cout << (i == 0 ? "" : " ") << w[i];
	}
	cout << endl;
	return 0;
}
