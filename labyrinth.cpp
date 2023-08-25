#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

string bfs(int startX, int startY, int endX, int endY, char** grid, int width, int height) {
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    const char directions[] = {'U', 'D', 'L', 'R'};

    queue<Point> q;
    vector<vector<Point>> parent(width, vector<Point>(height, {-1, -1}));
    q.push({startX, startY});
    parent[startX][startY] = {startX, startY};

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == endX && curr.y == endY) {
            break; 
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if (isValid(nx, ny, width, height) && grid[nx][ny] != '#' && parent[nx][ny].x == -1) {
                q.push({nx, ny});
                parent[nx][ny] = curr;
            }
        }
    }

    if (parent[endX][endY].x == -1) {
        return "NO";
    }

    string path = "";
    Point curr = {endX, endY};
    while (curr.x != startX || curr.y != startY) {
        Point prev = parent[curr.x][curr.y];
        for (int dir = 0; dir < 4; dir++) {
            if (curr.x - prev.x == dx[dir] && curr.y - prev.y == dy[dir]) {
                path = directions[dir] + path;
                break;
            }
        }
        curr = prev;
    }

    return path;
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

    int startX, startY, endX, endY;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    string path = bfs(startX, startY, endX, endY, grid, width, height);

    if (path == "NO") {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }

    // Deallocate memory
    for (int i = 0; i < width; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
