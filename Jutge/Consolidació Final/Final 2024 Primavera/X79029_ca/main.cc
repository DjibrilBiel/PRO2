#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("queue.hh")
#include "queue.hh"
#endif
#endif

struct Container {
public:
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
    	word = c.word;
    }
    Container(const string s)
    {
        word = s;
    }
    Container(const int x)
    {
        if (x != 0) {
            cout << "Error: invalid initialization from int to string container" << endl;
            exit(1);
        }
    	word = "";
    }
	Container &operator=(const Container &c)
	{
        if (this == &c) return *this;
    	word = c.word;
        return *this;
	}
	Container &operator+=(const Container &c)
	{
    	word += c.word;
        return *this;
	}
	Container &operator=(const int x)
	{
        if (x != 0) {
            cout << "Error: invalid assignment from int to string container" << endl;
            exit(1);
        }
    	word = "";
        return *this;
	}
	Container &operator=(const string s)
	{
    	word = s;
        return *this;
    }
};

istream &operator>>(istream &is, Container &c)
{
    is >> c.word;
    return is;
}

ostream &operator<<(ostream &os, Container c)
{
    os << c.word;
    return os;
}

Container operator+(Container c1, Container c2)
{
    Container c;
    c.word = c1.word+c2.word;
    return c;
}

int getIdQueue(string s)
{
  return atoi(s.substr(1).c_str());
}

void die(string message) {
    cout << message << endl;
    exit(1);
}

int main()
{
  string s1, s2, s3, s4, s5, s6, s7;
  int numqueues = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numqueues++;
  vector<Queue<Container> > q(numqueues);
  while (cin >> s1) {
    if (s1[0] == 'q') {
      int idqueue = getIdQueue(s1);
      cin >> s2;
      if (s2 == ".push(") {
          cin >> s3 >> s4;
          Container value = s3.substr(1, int(s3.size())-2);
          q[idqueue].push(value);
      } else if (s2 == ".pop();") {
          q[idqueue].pop();
      } else if (s2 == ".take(") {
          cin >> s3 >> s4 >> s5 >> s6;
          int idqueue2 = getIdQueue(s3);
          int k = atoi(s5.c_str());
          q[idqueue].take(q[idqueue2], k);
      } else {
          cout << "WRONG METHOD " << s2 << endl;
      }
    } else if (s1 == "cout<<") {
      cin >> s2 >> s3;
      int idqueue = getIdQueue(s2);
      if (s3 == "<<endl;") {
	cout << q[idqueue] << endl;
      } else if (s3 == ".size()<<endl;") {
	cout << q[idqueue].size() << endl;
      } else if (s3 == ".front()<<endl;") {
	cout << q[idqueue].front() << endl;
      } else {
	cout << "WRONG ENDING " << s3 << endl;
      }
    } else if (s1 == "exit(0);") {
      exit(0);
    } else {
      cout << "WRONG COMMAND " << s1 << endl;
    }
  }
}
