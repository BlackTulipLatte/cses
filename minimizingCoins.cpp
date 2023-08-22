#include <iostream>
using namespace std;

int main(){

    int coins, target;
    int numberCoins = 0;
    cin >> coins >> target;

    int coinValues[coins];
    long long numberCoins[target + 1];

    for(int i = 0; i < coins; i++){
        cin >> coinValues[i];
    }

    numberCoins[0] = 0;

    for(int i = 1; i < target; i++){
        numberCoins[i] = 1000000000;
        for(int j = 0; j < coins; j++){
            if(i >= coinValues[j]){
                numberCoins[i] = min(numberCoins[i], numberCoins[i - coinValues[j]] + 1);
            }
        }
    }




}