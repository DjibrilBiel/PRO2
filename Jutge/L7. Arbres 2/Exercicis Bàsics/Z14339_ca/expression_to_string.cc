#include "tree.hh"
using namespace pro2;
#include <vector>
#include <string>
using namespace std;

string expression_to_string(Tree<string> t) {
    if (not (t.value() == "+" or t.value() == "-" or t.value() == "*")) return t.value();

    vector<string> math(t.num_children());
    for (int i = 0; i < t.num_children(); ++i) math[i] = expression_to_string(t.child(i));

    string final = "(" + math[0];
    for (int i = 1; i < math.size(); ++i) final += " " + t.value() + " " + math[i];
    return final + ")";
}