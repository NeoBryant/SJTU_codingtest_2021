// passed


#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int reverse(string str){
    int num = 0;
    int len = str.length();
    reverse(str.begin(), str.end());
    for (int i = 0; i < len; ++i) {
        // int temp = str[i]-'0';
        num += str[i] - '0';
        if (i != len - 1)
        {
            num *= 10;
        }
    }
    return num;
}

int str2int(string str){
    int num = 0;
    int len = str.length();
    for (int i = 0; i < len; ++i){
        // int temp = str[i]-'0';
        num += str[i] - '0';
        if (i != len-1){
            num *= 10;
        }
    }
    return num;
}

int main(){

    // int N;
    string a, b;
    // cin >> N;
    // while (N--){
    cin >> a >> b;
    int res_1, res_2;
    res_1 = reverse(a) + reverse(b);
    res_2 = str2int(a) + str2int(b);

    string r_1 = to_string(res_1);
    if (reverse(r_1) == res_2){
        cout << res_2 << endl;
    } else{
        cout << "NO" << endl;
    }
    // }
}