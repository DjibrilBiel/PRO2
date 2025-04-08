#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string join(vector<string>::iterator ini, vector<string>::iterator fin, string sep);

int main() {
    string line;
    getline(cin, line);
    const string separator = line.substr(1, line.size() - 2);

    getline(cin, line);
    istringstream S(line);

    vector<string> words;
    string         word;
    while (S >> word) {
        words.push_back(word);
    }

    cout << '"' << join(words.begin(), words.end(), separator) << '"' << endl;

    return 0;
}
