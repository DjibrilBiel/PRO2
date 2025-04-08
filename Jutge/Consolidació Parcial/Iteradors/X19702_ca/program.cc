#include <iostream>
#include <list>
using namespace std;

int main()
{
 list<int> v;
 auto index = v.begin();

 string command;
 while (cin >> command) {
  if (command == "index++;") {
   ++index;
  } else if (command == "index--;") {
   --index;
  } else if (command == "v.push_front(") {
   int number;
   cin >> number;
   string ending;
   cin >> ending; // Això consumeix el ");"
   v.push_front(number);
   --index;
  } else if (command == "v.push_back(") {
   int number;
   cin >> number;
   string ending;
   cin >> ending; // Això consumeix el ");"
   v.push_back(number);
   if (index == v.end()) --index;
  } else if (command == "v.insert(index,") {
   int number;
   cin >> number;
   string ending;
   cin >> ending; // Això consumeix el ");"
   v.insert(index, number);
   --index;
  } else if (command == "cout<<v[index]<<endl;") {
   cout << *index << endl;
  }
 }
}