#include <iostream>
#include <string>
#include <map>
// #include <cstring>
// #include <algorithm>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int y){
    if (y%4 == 0 && y%100 != 0) return true;
    return false;
}

int daysOfYear[3000]; //每一年的时间
int daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void func(){
    for (int i = 0; i < 3000; ++i){
        if (isLeapYear(i+1)){
            daysOfYear[i] = 366;
        } else{
            daysOfYear[i] = 365;
        }
    }
}

int dif(int y, int m, int d){
    int days = 0;
    for (int i = 0; i < y-1; ++i){
        days += daysOfYear[i];
    }
    for (int i = 0; i < m-1; ++i){
        if (isLeapYear(y) && i == 1){
            days += 29;
        } else {
            days += daysOfMonth[i];
        }
    }
    days += d;
    return days;
}

int main(){
    // 定义月和周英文名
    map<string, int> months;
    const string str_month[12] = {"January", "February", "March", "April", 
                                    "May", "June", "July", "August", 
                                    "September", "October", "November", "December"};
    for (int i = 0; i < 12; ++i) {
        months[str_month[i]] = i + 1;
    }
    map<int, string> weeks;
    const string str_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; ++i) {
        weeks[i] = str_week[i];
    }
    // 输入
    int day, month,year;
    string in_month;
    int difs;

    // 预处理
    func();

    while (cin >> day >> in_month >> year) {
        month = months[in_month]; // 月份转化为数字
        // 首先计算该日期与公元1年1月1号相差时间
        difs = dif(year, month, day);
        // 再mod7求余数知道星期几
        int week = (difs-2)%7;
        cout << weeks[week] << endl;
        // cout << difs << endl;
    }

    return 0;
}