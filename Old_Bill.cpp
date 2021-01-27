// passed

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

    int N;
    int x, y, z;
    int a, b, total;
    while (cin >> N){
        cin >> x >> y >> z;
        int mid = x*1000+y*100+z*10;
        int total = 0; //总价
        int price = 0; //单价
        bool hasSol = false;
        for (int i = 9; i > 0; --i){
            for (int j = 9; j >=0; --j){
                total = mid + i * 10000 + j;
                if (total % N == 0) {
                    hasSol = true;
                    price = total / N;
                    a = i;
                    b = j;
                    break;
                }
            }
            if (hasSol){
                break;
            }
        }
        if (hasSol){
            cout << a << ' ' << b << ' ' << price << endl;
        } else{
            cout << 0 << endl;
        }
    }


    return 0;
}