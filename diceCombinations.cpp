#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
                dp[i] %= 1000000007;
            }
        }
    }

    cout << dp[n];

}