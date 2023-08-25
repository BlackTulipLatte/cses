#include <iostream>
using namespace std;
#include <unordered_map>

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> umap;
    int distinct = 0;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(umap.find(x) == umap.end()){
            umap[x] = 1;
            distinct++;
        }
    }
    cout << distinct << endl;
}