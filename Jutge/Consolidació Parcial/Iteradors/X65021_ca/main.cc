// Add or remove includes
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <cstdlib>

using namespace std;

#include "appendReverseOrder.hh"

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

struct Test {
    list<int> l;
};

list<int> readList(string line)
{
    istringstream mycin(line);
    list<int> l;
    int x;
    while (mycin >> x)
        l.push_back(x);
    return l;
}

void writeList(list<int> l)
{
    bool writespace = false;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        if (writespace) cout << " ";
        writespace = true;
        cout << *it;
    }
    cout << endl;
}

#endif


int main()  {
    vector<Test> test;
    string line;
    while (getline(cin, line)) {
        Test t;
        t.l = readList(line);
        test.push_back(t);
    }
    for (int i=0;i<int(test.size());i++) {
        vector<list<int>::iterator > v;
        list<int> &l = test[i].l;
        for (list<int>::iterator it = l.begin(); it != l.end(); it++)
            v.push_back(it);
        list<int> laux = l;
        appendReverseOrder(l);
        laux = list<int> ();
        list<int>::iterator it = l.begin();
        for (int iv = 0; iv < int(v.size()); iv++, ++it) {
            if (it != v[iv]) {
                cout << "Error: original elements of list have been altered or do not occupy first, third, fifth, ... positions";
                exit(0);
            }
        }
        
        writeList(l);
    }
}
