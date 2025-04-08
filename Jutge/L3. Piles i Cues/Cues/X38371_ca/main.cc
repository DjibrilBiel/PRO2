#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int sum = 0, min = 1000, max = -1000, count = 0;
    
    int n;
    while (cin >> n and not (n > 1000 or n < -1001)) {
        if (n == -1001) {
            if (q.size() > 0) {
                int m = q.front();
                sum -= m;
                q.pop();
                --count;

                if (count == 0) cout << 0 << endl;
                else {
                    if (m == min or m == max) {
                        queue<int> temp = q;
                        min = temp.front();
                        max = min;
                        while (temp.size() > 0) {
                            int x = temp.front();
                            temp.pop();
                            if (x < min) min = x;
                            if (x > max) max = x;
                        }
                    }
                    double media = double(sum) / count;
                    cout << "min " << min << "; max " << max << "; media " << media << endl;
                }
            } else cout << 0 << endl;
        } else {
            q.push(n);
            ++count;
            sum += n;
            if (count == 1) {
                min = n;
                max = n;
            } else {
                if (n < min) min = n;
                if (n > max) max = n;
            }
            double media = double(sum) / count;
            cout << "min " << min << "; max " << max << "; media " << media << endl;
        }
    }
}