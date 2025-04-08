#include <iostream>
#include <string>
#include <map>
// Add more includes if you wish.

using namespace std;

// Add auxiliary functions if you wish.

int main()
{
  // Declaración del map, junto con variables para el tamaño y el offset.
  map<int, int> v;
  int offset = 0, size = 0;
  string command;
  while (cin >> command) {
    if (command == "v.push_back(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ");"
      v[offset + size] = val;
      ++size;
    } else if (command == "v.push_front(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ");"
      --offset;
      v[offset] = val;
      ++size;
    } else if (command == "v.pop_front();") {
      v.erase(offset);
      ++offset;
      --size;
    } else if (command == "v.pop_back();") {
      v.erase(offset + size - 1);
      --size;
    } else if (command == "v.resize(") {
      int newsize;
      cin >> newsize;
      string ending;
      cin >> ending; // Això consumeix el ");"
      if (newsize < size) {
        for (int i = offset + newsize; i < offset + size; ++i)
          v.erase(i);
        size = newsize;
      } else if (newsize > size) {
        for (int i = size; i < newsize; ++i)
          v[offset + i] = 0; // Valor por defecto.
        size = newsize;
      }
    } else if (command == "cout<<v[") {
      int index;
      cin >> index;
      string ending;
      cin >> ending; // Això consumeix el "];"
      cout << v[offset + index] << endl;
    } else if (command == "cout<<v;") {
      if (size > 0) {
        cout << v[offset];
        for (int i = 1; i < size; ++i)
          cout << ',' << v[offset + i];
      }
      cout << endl;
    } else if (command == "v[") {
      int index;
      cin >> index;
      string mid;
      cin >> mid; // Això consumeix el "]="
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ";"
      v[offset + index] = val;
    } else if (command == "//") {
      string comment;
      getline(cin, comment);
      cout << "//" << comment << endl;
    } else {
      cout << "Wrong command '" << command << "'" << endl;
      string discard;
      getline(cin, discard);
    }
  }
}
