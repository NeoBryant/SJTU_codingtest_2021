// passed


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isDuplicated(int* arr, int count, int num){
    for (int i = 0; i < count; ++i){
        if (num == arr[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    int arr[1000];
    int count = 0;

    for (int i = 0; i < N; ++i){
        int num;
        cin >> num;
        if (!isDuplicated(arr,count,num)){
            arr[count] = num;
            ++count;
        }
    }

    // sort
    int temp;
    for (int i = 0; i < count; ++i){
        for (int j = 0; j < count-1-i; ++j){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < count; ++i){
        cout << arr[i];
        if (i != count-1){
            cout << ' ';
        } else {
            cout << endl;
        }
    }


    return 0;
}