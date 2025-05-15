
#include <cassert>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

#include "finder.hh"
#include "test-object.hh"
using namespace pro2;

class FinderTester {
    unordered_map<string, TestObject> objects_;
    unordered_map<const TestObject *, string> pointer2id_;
    Finder<TestObject> *finder_;

 public:
    FinderTester() {
        finder_ = new Finder<TestObject>();
    }

    ~FinderTester() {
        delete finder_;
    }

    void add(string id, Rect r) {
        auto ins = objects_.insert({id, TestObject(r)});
        assert(ins.second);   // Should have been inserted
        auto it = ins.first;  // iterator to inserted element
        finder_->add(&it->second);
        pointer2id_.insert({&it->second, id});
    }

    void remove(string id) {
        auto it = objects_.find(id);
        assert(it != objects_.end());
        finder_->remove(&it->second);
        pointer2id_.erase(&it->second);
        objects_.erase(it);
    }

    void update(string id, Rect r) {
        auto it = objects_.find(id);
        assert(it != objects_.end());
        it->second = TestObject(r);
        finder_->update(&it->second);
    }

    void reset() {
        objects_.clear();
        pointer2id_.clear();
        delete finder_;
        finder_ = new Finder<TestObject>();
    }

    set<string> query(Rect r) {
        auto queryResult = finder_->query(r);
        set<string> ids;
        for (auto pr : queryResult) {
            auto it = pointer2id_.find(pr);
            assert(it != pointer2id_.end());
            ids.insert(it->second);
        }
        return ids;
    }
};

string read_id() {
    string id;
    cin >> id;
    return id;
}

Rect read_rect() {
    Rect r;
    cin >> r.left >> r.top >> r.right >> r.bottom;
    return r;
}

int main() {
    FinderTester tester;

    char cmd;
    while (cin >> cmd) {
        switch (cmd) {
            case '+': {  // add
                auto id = read_id();
                auto rect = read_rect();
                tester.add(id, rect);
                break;
            }
            case '-': {  // remove
                auto id = read_id();
                tester.remove(id);
                break;
            }
            case '=': {  // update
                auto id = read_id();
                auto rect = read_rect();
                tester.update(id, rect);
                break;
            }
            case '?': {  // query
                auto rect = read_rect();
                auto ids = tester.query(rect);
                if (ids.empty()) {
                    cout << "empty" << endl;
                } else {
                    cout << "objs:";
                    for (auto id : ids) {
                        cout << ' ' << id;
                    }
                    cout << endl;
                }
                break;
            }
            case '0': {  // reset
                tester.reset();
                break;
            }
        }
    }

    return 0;
}