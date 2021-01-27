// passed

#include <iostream>
#include <string>

using namespace std;

int main(){

    string word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count[26] = {0};
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i){
        for (int j = 0; j < word.length(); ++j){
            if (str[i] == word[j]){
                ++count[j];
                break;
            }
        }
    }

    for (int i = 0; i < word.length(); ++i){
        cout << word[i] << ":" << count[i] << endl;
    }

    return 0;
}