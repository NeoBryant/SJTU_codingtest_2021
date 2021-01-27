#include <iostream>
// #include <vector>
#include <string>
#include <sstream>
// #include <cstring>
// #include <algorithm>
// #include <typeinfo>
using namespace std;

string add(string a, string b){
    int len_a = a.length(), len_b = b.length();
    string res = ""; // 结果
    int count = 0; //进位
    int unit;      // 个位

    // 进行加
    for (int ia = len_a - 1, ib = len_b - 1; ia >= 0 || ib >= 0; --ia, --ib) {
        if (ia >= 0 && ib >= 0){
            unit = (a[ia] - '0' + b[ib] - '0' + count) % 10; // 个位相加
            count = (a[ia] - '0' + b[ib] - '0' + count) / 10; // 进位
            res = to_string(unit) + res;
        } else if (ia >= 0 && ib < 0) {
            unit = (a[ia] - '0' + count) % 10; // 个位
            count = (a[ia] - '0' + count) / 10; // 进位
            res = to_string(unit) + res;
        } else if (ia < 0 && ib >= 0) {
            unit = (b[ib] - '0' + count) % 10;  // 个位
            count = (b[ib] - '0' + count) / 10; // 进位
            res = to_string(unit) + res;
        }
        // if (ia == 0 && ib == 0 && count != 0){
        //     res = to_string(count) + res;
        // }
    }
    if (count != 0){
        res = to_string(count) + res;
    }
    return res;
}

string minu(string a, string b) {
    bool sign = true; // 正负号
    int len_a = a.length(), len_b = b.length();
    int len_A, len_B;
    string res = ""; // 结果
    int unit;      // 个位
    string A, B; // 确定减数与被减数，A - B
    if (len_a > len_b) {
        A = a; B = b;
    } else if (len_a < len_b) {
        A = b; B = a;
        sign = false;
    } else {
        bool isEqual = true;
        for (int i = 0; i < len_a; ++i){
            if (a[i] > b[i]) {
                A = a; B = b;
                isEqual = false;
                break;
            } else if (a[i] < b[i]) {
                A = b; B = a;
                // cout << "hjvashkj asdk";
                sign = false;
                isEqual = false;
                break;
            } 
        }
        if (isEqual) return "0";
    }
    len_A = A.length();
    len_B = B.length();

    // 进行减
    for (int ia = len_A-1, ib = len_B-1; ia >= 0 || ib >= 0; --ia, --ib) {
        if (ia >= 0 && ib >= 0) {
            if (A[ia] - '0' >= B[ib] - '0') {
                unit = (A[ia] - '0') - (B[ib] - '0');
            }
            else {
                unit = (A[ia] - '0' + 10) - (B[ib] - '0');
                // 处理借位
                for (int j = ia-1; j >= 0; --j){
                    if (A[j] >= 1) {
                        A[j] = A[j] - 1;
                        break;
                    } else { // 向前借位
                        A[j] = A[j] + 9;
                    }
                }
            }
            res = to_string(unit) + res;
        } else if (ia >= 0 && ib < 0) {
            res = to_string(A[ia] - '0') + res;
        }
    }
    // 消除前置0
    int pos = -1;
    for (int i = 0; i < res.length(); ++i){
        if (res[i] == '0') {
            ++pos;
        } else {
            break;
        }
    }
    if (pos != -1) {
        res = res.substr(pos+1);
    }
    // 添加负号
    if (!sign) {
        res = "-" + res;
    }
    return res;
}

string multiply(string a, string b) {
    int len_a = a.length(), len_b = b.length();
    string res = "";
    string tempRes[len_b]; // 记录每位乘的结果
    int num1, num2;
    for (int i = 0; i < len_b; ++i) {
        tempRes[i] = "";
        for (int j = 0; j < i; ++j){
            tempRes[i] += "0";
        }
    }
 
    // 计算每位乘的结果
    for (int ib = len_b - 1, count = 0; ib >= 0; --ib, ++count) { //b中的每一位
        int unit = 0; // 个位
        int ten = 0;  // 十位
        num1 = b[ib] - '0';
        for (int ia = len_a - 1; ia >= 0; --ia) {
            num2 = a[ia] - '0';
            unit = (num1 * num2 + ten) % 10;
            ten = (num1 * num2 + ten) / 10;
            tempRes[count] = to_string(unit) + tempRes[count];
        }
        if (ten > 0) {
            tempRes[count] = to_string(ten) + tempRes[count];
        }
    }
    // 把每位相乘结果最后求和
    for (int i = 0; i < len_b; ++i){
        res = add(res, tempRes[i]);
    }
    return res;
}

int main(){
    string num1, num2;
    cin >> num1 >> num2;  //输入

    // 输出
    cout << add(num1, num2) << endl; 
    cout << minu(num1, num2) << endl;
    cout << multiply(num1, num2) << endl;

    return 0;
}
