#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    int min = 0, max = 0, size = 0, sum = 0;
    double mit = 0;
    int ins, n;

    bool empty = true, finish = false;
    while (not finish) {
        if (empty) {
            bool stop = false;
            while (cin >> ins >> n and not (ins == 0 and n == 0) and not stop) {
                if (ins == -1) {
                    l.push_back(n);

                    min = max = sum = n;
                    mit = double(n);
                    size = 1;

                    cout << max << ' ' << min << ' ' << mit << endl;

                    stop = true;
                } else cout << 0 << endl;
            }
            empty = false;
        } else cin >> ins >> n;
        if (ins == 0 and n == 0) finish = true;

        if (not finish) {
            if (ins == -1) {
                l.push_back(n);

                if (min > n) min = n;
                else if (max < n) max = n;

                sum += n;
                ++size;
                mit = double(sum) / size;
            } else {
                bool found = false;
                auto it = l.begin();
                while (it != l.end() and not found) {
                    if (n == *it) {
                        it = l.erase(it);
                        found = true;
                    } else ++it;
                }
                empty = l.empty();

                if (found) {
                    sum -= n;
                    --size;
                    if (not empty) {
                        mit = double(sum) / size;

                        if (min == n or max == n) {
                            auto it = l.begin();
                            min = max = *it;
                            for (++it; it != l.end(); ++it) {
                                if (min > *it) min = *it;
                                else if (max < *it) max = *it;
                            }
                        }
                    }
                }
            }

            if (not empty) cout << min << ' ' << max << ' ' << mit << endl;
            else cout << 0 << endl;
        }
    }
}