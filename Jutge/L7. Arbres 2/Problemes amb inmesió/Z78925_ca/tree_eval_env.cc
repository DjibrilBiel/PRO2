#include "bintree.hh"
#include "util.hh"
using namespace pro2;
#include <string>
#include <map>
using namespace std;

int tree_eval_env(BinTree<string> t, const map<string, int>& env) {
    string val = t.value();
    if (not (val == "+" or val == "-" or val == "*")) {
        if (is_number(val)) return string_to_int(val);
        auto it = env.find(val);
        return it->second;
    }

    int left = tree_eval_env(t.left(), env);
    int right = tree_eval_env(t.right(), env);

    if (val == "+") return left + right;
    if (val == "-") return left - right;
    return left * right;
}