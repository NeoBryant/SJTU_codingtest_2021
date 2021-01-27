#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// #include <cstring>
// #include <algorithm>
using namespace std;

typedef struct node{
    string name;
    vector<node *> children;
} node;



//将路径字符串划分为vector
void split(const string &s, vector<string> &sv){
    sv.clear();
    string name = "";
    for (int i = 0; i < s.length(); ++i){
        if (s[i] != '\\'){
            name += s[i];
        } else{
            sv.push_back(name);
            name = "";
        }
    }
    if (name != ""){
       sv.push_back(name);
    }
    return;
}

void addChild(node *root, string name){

    return;
}

bool hasChild(node *root, string name){


    return false;
}

    int main()
{
    node *root;

    int n;
    string str;
    while (cin >> n){
        if (n == 0) break;
        while(n--){
            vector<string> path;
            cin >> str;
            split(str, path);
            
            for (int i = 0; i < path.size(); ++i){
                
            }
        }
    }

        return 0;
}