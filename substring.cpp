#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void substring(string s, string o) {
if (s.length()==0){
cout<<o<<" ";
return;}
substring(s.substr(1),o);
substring(s.substr(1),o+s[0]);
}

int main() {
    string s = "abc";
    string o = "";  // Make sure there's enough space
    substring(s, o);
    return 0;
}
