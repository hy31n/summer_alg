#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main() {
    int arr[100];
    int n, i = 0;
    cin >> n;

    for(; n > 0; i++){
        arr[i] = n % 10;
        n /= 10;
    }

    sort(arr, arr + i, compare);

    for(int j=0; j<i; j++){
        cout << arr[j];
    }
    return 0;
}