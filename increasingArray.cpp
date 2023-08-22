#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long arr[n];

    long long ans = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << ans;
}