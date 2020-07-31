#include <iostream>
#include <map>
#include <hash_map> //哈希表
#include <unordered_map> //哈希表
using namespace std;

int main()
{
    //map有序存储，unordermap无序存储
     map<string, string> data;//map<int, string> data; 可以用data[n]寻址
     data.insert(make_pair("1", "a"));
     data.insert(make_pair("2", "qa"));
     data.insert(make_pair("3", "wa"));
     data.insert(make_pair("4", "ea"));
     data.insert(make_pair("5", "ra"));

     map<string, string>::iterator iter;
     iter = data.find("2");

     unordered_map<string,string> data2;
     data2.insert(make_pair("1", "a"));
     data2.insert(make_pair("2", "qa"));
     data2.insert(make_pair("3", "wa"));
     data2.insert(make_pair("4", "ea"));
     data2.insert(make_pair("5", "ra"));

     //hash_map<string, string> data3;




     cout << iter->second << endl;
     return 0;
} 

