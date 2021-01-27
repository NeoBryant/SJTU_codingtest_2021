// passed


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char find(char a){
    string pat = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
    char b;

    for (int i = 0; i < pat.length(); ++i){
        if (a == pat[i]){
            b = pat[i-1];
        }
    }
    return b;
}

int main(){
    string input;
    string output = "";
    string pat = "QWERTYUIOP{}}|ASDFGHJKL:\"ZXCVBNM<>?";
    //cin >> input;
    getline(cin, input);
    for (int i = 0; i < input.length(); ++i){
        char temp;
        if (input[i] == ' '){
            temp = input[i];
        } else{
            temp = find(input[i]);
        }
        output += temp;
    }
    cout << output << endl;

    return 0;
}