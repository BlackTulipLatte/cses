#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;

        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }

        if(a * 2 < b){
            cout << "NO" << endl;
        } 
        else {
            int sum = a + b;
            if(sum % 3 == 0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }
}