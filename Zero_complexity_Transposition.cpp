#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(){
    int n;
    vector<int> arr;

    cin >> n;

    for (int i = 0; i < n; ++i){
        int num = 0;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = n-1; i >= 0; --i){
        cout << arr[i];
        if (i != 0) cout << ' ';
    }


    return 0;
}