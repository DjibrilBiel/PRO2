#include "tree.hh"
using namespace pro2;
#include <iostream>
using namespace std;

void print_folders_func(Tree<string> t, int indent_size, int level) {
    if (t.empty()) return;

    for (int i = 0; i < level; ++i) for (int j = 0; j < indent_size; ++j) cout << ' ';
    cout << t.value() << endl;

    for (int i = 0; i < t.num_children(); ++i) print_folders_func(t.child(i), indent_size, level + 1);
}

void print_folders(Tree<string> t, int indent_size) {
    print_folders_func(t, indent_size, 0);
    cout << endl;
}