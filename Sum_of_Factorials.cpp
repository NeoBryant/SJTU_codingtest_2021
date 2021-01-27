// passed  暴力土方法解

#include <iostream>
#include <string>
// #include <cstring>
// #include <algorithm>
using namespace std;

int func(int n){
    int num = 1;
    for (int i = 2; i <= n; ++i){
        num *= i;
    }
    return num;
}


int main(){

    int n;
    while (cin >> n){
        bool yes = false;
        int sum = 0;
        for (int i = 0; i < 2*n; ++i){
            sum += func(i);

            if (sum == n){
                yes = true;
                break;
            }
            if (sum > n){
                break;
            }
        }

        if (yes)
        {
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}