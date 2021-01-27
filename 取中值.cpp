#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr;
    
    int a, b, c, d;
    int len1, len2, len;
    cin >> len1 >> len2;
    for (int i = 0; i < len1; ++i){
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }
    for (int i = 0; i < len2; ++i){
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    cin >> a >> b >> c >> d;
    len = b - a + d - c + 2;
    
    for (int i = a-1; i < b; ++i){
        arr.push_back(arr1[i]);
    }

    for (int i = c-1; i < d; ++i){
        arr.push_back(arr2[i]);
    }

    // sort

    cout << arr[(len-1)/2] << endl;

    return 0;
}