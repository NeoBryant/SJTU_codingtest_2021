// #include <string>
#include <iostream>
// #include <vector>
// #include <cmath>
// #include <typeinfo>

using namespace std;


/*
素数判断法： 超时
 */
// const int MAX = 10000;
// // 判断一个数是否为素数
// bool isPrime(int n){
//     if (n == 2 || n == 3) {
//         return true;
//     }
//     for (int i = 2; i < n; ++i){
//         if (n%i == 0) {
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     int arr[MAX];
//     int k;
//     int count = 0;
//     for (int i = 2; count < MAX; ++i){
//         if (isPrime(i)){
//             arr[count++] = i;
//         }
//     }
//     while (cin >> k){ // 找到第k个素数
//         cout << arr[k-1] << endl;;
//     }
//     return 0;
// }

/* 筛选法
该方法不是用来具体判断一个数是否是素数，而是用于判断一个范围内所有的素数。
该方法的原理是：首先生成数组，然后从第一个开始依次标注它的倍数，然后从下一个没有被标注的开始，标注它所有的倍数，
            这样依次下去，最后没有被标注的都是素数。

第10000个素数是104729
 */
#define MAX 105000
unsigned long r[MAX], p[10000], n, t;
int main(){
	int k;
	for(int i = 0; i < MAX; ++i) {
        r[i] = i; // r[0,1,2,...,n]=[0,1,2,3,...,n]
    }
	for(int i = 0; i < MAX; ++i){
		if(r[i] > 1) {
			for(int j = 2; j < MAX; ++j) {
				if((t = i*j) <= MAX) {
                    r[t] = 0;
                } else {
                    break;
                }
            }
		}
	}
	for(int m = 0, i = 0; i < MAX; ++i){
	    if(r[i] > 1) {
            p[m++] = r[i];
        }
		if(m >= 10000) {
            break;
        }
	}

	while(cin >> k){
		cout << p[k-1] << endl;
	}
}