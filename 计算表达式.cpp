#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
// #include <stream>
// #define MAX 1000

using namespace std;

/*
对于一个**不存在括号**的表达式进行计算
存在多种数据，每组数据一行，表达式不存在空格
 */
int main(){
    string str;
    cin >> str;

    vector<char> opts; // 操作符
    vector<float> nums; 
    string number = ""; // 记录出现的数字，并用于转化为int
    // int number2;
    float num1, num2; // 计算num1 op num2 = num1
    
    for (int i = 0; i < str.length(); ++i){
        if (str[i] <= '9' && str[i] >= '0') {
            number = number + str[i];
        } else { 
            // 处理数字
            nums.push_back(atof(number.c_str())); // string->int
            // cout << number.c_str() << " ";
            number = "";
            // 处理计算
            if (str[i] == '*' || str[i] == '/') {
                if (opts.size() != 0) { // 若栈非空
                    if (opts.back() == '*' || opts.back() == '/')
                    { // 若栈顶元素优先级更低
                        // 先计算
                        num2 = nums.back();
                        nums.pop_back();
                        num1 = nums.back();
                        nums.pop_back();
                        if (opts.back() == '*')
                            num1 = num1 * num2;
                        else
                            num1 = num1 / num2;
                        opts.pop_back();
                        // 再入栈
                        nums.push_back(num1);
                    }
                }
            } else if (str[i] == '+' || str[i] == '-') {
                if (opts.size() != 0) { // 若栈顶元素优先级更高或相等（即非空），则一直计算直到栈空
                    // 先计算
                    while (opts.size() > 0) {
                        // 先计算
                        num2 = nums.back(); // 取数字
                        nums.pop_back();
                        num1 = nums.back();
                        nums.pop_back();
                        if (opts.back() == '*') 
                            num1 = num1 * num2;
                        else if (opts.back() == '/') 
                            num1 = num1 / num2; 
                        else if (opts.back() == '+')
                            num1 = num1 + num2;
                        else if (opts.back() == '-')
                            num1 = num1 - num2;
                        opts.pop_back();      // 操作符栈顶元素出栈
                        nums.push_back(num1); // 数字入栈
                    }
                }
            }
            opts.push_back(str[i]); //入栈
        }
        // 若为最后一个数字
        if (i == str.length()-1){
            nums.push_back(atoi(number.c_str())); // string->int
            // cout << number.c_str() << " ";
            number = "";
        }
    }
    
    // 若操作
    while (opts.size() > 0) {
        // 先计算
        num2 = nums.back(); // 取数字
        nums.pop_back();
        num1 = nums.back();
        nums.pop_back();
        if (opts.back() == '*') 
            num1 = num1 * num2;
        else if (opts.back() == '/') 
            num1 = num1 / num2; 
        else if (opts.back() == '+')
            num1 = num1 + num2;
        else if (opts.back() == '-')
            num1 = num1 - num2;
        opts.pop_back();      // 操作符栈顶元素出栈
        nums.push_back(num1); // 数字入栈
    }
    if (nums.size() > 1) cout << "WRONG!" << endl;
    cout << nums.back() << endl;

    return 0;
}