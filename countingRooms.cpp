#include <iostream>
using namespace std;

void dfs(int x, int y, char** grid, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    if (grid[x][y] == '#') {
        return;
    }

    grid[x][y] = '#';

    dfs(x + 1, y, grid, width, height);
    dfs(x - 1, y, grid, width, height);
    dfs(x, y + 1, grid, width, height);
    dfs(x, y - 1, grid, width, height);
}

int main() {
    int width, height;
    cin >> width >> height;

    char** grid = new char*[width];  

    for (int i = 0; i < width; i++) {
        grid[i] = new char[height];  
        for (int j = 0; j < height; j++) {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j] == '.') {
                rooms++;
                dfs(i, j, grid, width, height);
            } else if (grid[i][j] == '#') {
                continue;
            }
        }
    }

    cout << rooms << endl;

    // Deallocate memory
    for (int i = 0; i < width; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
