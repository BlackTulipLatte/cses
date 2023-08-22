#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int acc = 2;

    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }

    while(acc <= n){
        cout << acc << " ";
        acc += 2;
    }

    acc = 1;

    while(acc <= n){
        cout << acc << " ";
        acc += 2;
    }

    return 0;

    // 6
    // 1 3 6 4 2 5


}