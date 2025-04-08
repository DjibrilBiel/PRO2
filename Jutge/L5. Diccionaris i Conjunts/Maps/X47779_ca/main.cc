
#include <map>
#include <iostream>
using namespace std;

string to_morse(string s, const map<char, string>& M) {
   string morse = "";
   if (s.size() == 0) return morse;
   
   map<char, string>::const_iterator it = M.find(toupper(s[0]));
   if (it != M.end()) {
      morse = it->second;
   }
   for (int i = 1; i < s.size(); ++i) {
      map<char, string>::const_iterator it = M.find(toupper(s[i]));
      if (it != M.end()) {
         morse += " " + it->second;
      }
   }

   return morse;
}

int main() {
   map<char, string> M;
   M['A'] = ".-";   M['B'] = "-..."; M['C'] = "-.-."; M['D'] = "-..";
   M['E'] = ".";    M['F'] = "..-."; M['G'] = "--.";  M['H'] = "....";
   M['I'] = "..";   M['J'] = ".---"; M['K'] = "-.-";  M['L'] = ".-..";
   M['M'] = "--";   M['N'] = "-.";   M['O'] = "---";  M['P'] = ".--.";
   M['Q'] = "--.-"; M['R'] = ".-.";  M['S'] = "...";  M['T'] = "-";
   M['U'] = "..-";  M['V'] = "...-"; M['W'] = ".--";  M['X'] = "-..-";
   M['Y'] = "-.--"; M['Z'] = "--..";
   M['0'] = "------"; M['1'] = ".-----"; M['2'] = "..---"; M['3'] = "...--";
   M['4'] = "....-";  M['5'] = ".....";  M['6'] = "-...."; M['7'] = "--...";
   M['8'] = "---..";  M['9'] = "----.";

   string s;
   getline(cin, s);
   cout << to_morse(s, M) << endl;   
}
