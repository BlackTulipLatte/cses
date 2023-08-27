#include <iostream>
using namespace std;
#include <string>

int main(){
    string m, n;
    long long ans = 0;
    cin >> m >> n;

    while(m.find(n) != -1){
        m = m.substr(0, m.find(n)) + m.substr(m.find(n) + n.length());
        ans++;
    }

    cout << ans;
}