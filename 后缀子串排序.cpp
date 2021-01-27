#include <iostream>
#include <string>
#include <vector>

using namespace std;



// 比较a和b的优先级，若a<b则交换
bool isExchanged(string a, string b){
    // 判断a<b->true
    for (int ia = 0, ib = 0; ia < a.length() && ib < b.length(); ++ia, ++ib){
        if (a[ia] - 'a' > b[ib] - 'a'){
            return true;
        } else if (a[ia] - 'a' < b[ib] - 'a'){
            return false;
        } 
    }
    if (a.length() > b.length()){ // o 与 oa 这种情况，优先级 o>oa
        return true;
    }

    return false;
}


int main(){
    vector<string> arr; // 记录后缀子串
    string str; //输入字符串
    string temp; // 临时交换
    cin >> str;

    for (int i = 0; i < str.length(); ++i){
        arr.push_back(str.substr(i));
    }

    for (int i = 0; i < arr.size(); ++i){
        for (int j = 0; j < arr.size()-i-1; ++j){
            if (isExchanged(arr[j], arr[j+1])){ // 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << endl;
    }

    return 0;
}