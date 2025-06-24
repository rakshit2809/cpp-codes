#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> mymap;

    pair<string,int> p("avc",23);
    mymap.insert(p);//way 1 to insert
    mymap["das"]=12; //way 2 to insert

//accessing the element
cout<<mymap["avc"]<<endl;
cout<<mymap.at("avc")<<endl;
//cout<<mymap.at("avaassc")<<endl; // throws out of range exception
//cout<<mymap["aqwdqvc"]<<endl; //returns a default value 0

//check presence of a key in unordered map
cout<<mymap.count("avc")<<endl; //returns 1
cout<<mymap.count("awevc")<<endl; // returns 0

//update
mymap["das"]=121;

//erase
mymap.erase("das");
cout<<mymap.count("das")<<endl;

return 0;
}