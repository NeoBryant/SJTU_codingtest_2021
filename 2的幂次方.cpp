#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>

using namespace std;

const string one = "2(0)";
const string two = "2";

// return: 2^index
int power(int index){
    return (int)pow(2.0, index);
}


// 递归
string getStr(int num){
    int rest = num; //记录余数
    string res = "";
    vector<int> vec; 
    if (num == 1) {
        return one;
    } else if (num == 2) {
        return two;
    } else {
        bool isFirst = true; //判断是否为第一项
        while (rest > 0){
            for (int i = 0; i < 100000000; ++i){ // 找到最大2次幂构成
                if (rest >= power(i) && rest < power(i+1)){
                    if (isFirst){ // 若为第一项    
                        isFirst = false;
                    } else {  // 若不为第一项
                        res += "+";
                    }
                    if (i == 0) {
                        res = res + "2(0)";
                    } else if (i == 1){
                        res = res + "2";
                    } else {   
                        res = res + "2(" + getStr(i) + ")";
                    }
                    rest -= power(i);  // 余数继续计算
                    break; 
                }
            }   
        }
    }
    return res;
}

int main() {
    int num;  //输入
    cin >> num;

    cout << getStr(num) << endl; // 输出
    return 0;
}