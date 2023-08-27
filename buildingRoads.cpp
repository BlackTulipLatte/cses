#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> adj(202020);
vector<bool> visited(202020);
vector<int> bridges;


void dfs(int node){
    visited[node] = true;
    for(auto child: adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

int main(){
    int cities, roads;
    cin >> cities >> roads;

    for(int i = 0; i < roads; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= cities; i++){
        if(!visited[i]){
            dfs(i);
            bridges.push_back(i);
        }
    }

    cout << bridges.size() - 1 << endl;
    for(int i = 0; i < bridges.size() - 1; i++){
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
}