// passed

#include <iostream>
#include <string>
using namespace std;

// 输入字符串转成int的年、月、日
void string2date(string str, int &y, int &m, int &d){
    y = 0; m = 0; d = 0;
    for (int i = 0; i < 4; ++i){
        y += str[i]-'0';
        if (i != 3) y *= 10;
    }
    for (int i = 4; i < 6; ++i){
        m += str[i]-'0';
        if (i != 5) m *= 10;
    }
    for (int i = 6; i < 8; ++i){
        d += str[i]-'0';
        if (i != 7) d *= 10;
    }
}

// 判断是否为闰年
bool isLeapYear(int y){
    if (y%4 == 0 && y%100 != 0) return true;
    return false;
}

void addOneDay(int &y, int &m, int &d){
    // 28/29: 2
    // 30: 4、6、9、11
    // 31: 1、3、5、7、8、10、12
    return;
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
    func();

    string begin_date, end_date;
    cin >> begin_date >> end_date;
    int b_y, b_m, b_d, e_y, e_m, e_d;

    // string转年月日
    string2date(begin_date, b_y, b_m, b_d);
    string2date(end_date, e_y, e_m, e_d);
    
    //算差值
    int res = dif(e_y, e_m, e_d) - dif(b_y, b_m, b_d) + 1;
    // cout << dif(e_y, e_m, e_d) << " " << dif(b_y, b_m, b_d) << endl;
    cout << res << endl;

    return 0;
}