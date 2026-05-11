#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 4

// Structure for a cell
struct Node {
    int x, y;
    int g, h, f;
    Node* parent;
};

// Heuristic function (Manhattan Distance)
int calculateH(int x, int y, int goalX, int goalY) {
    return abs(x - goalX) + abs(y - goalY);
}

// Check if cell is valid
bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Print path
void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    cout << "(" << node->x << "," << node->y << ") ";
}

// A* Algorithm
void aStar(int grid[ROW][COL], int startX, int startY, int goalX, int goalY) {

    // Closed list
    bool closed[ROW][COL] = {false};

    // Open list (min heap based on f value)
    auto cmp = [](Node* a, Node* b) {
        return a->f > b->f;
    };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> open(cmp);

    // Start node
    Node* start = new Node{startX, startY, 0, 0, 0, NULL};
    start->h = calculateH(startX, startY, goalX, goalY);
    start->f = start->g + start->h;

    open.push(start);

    // Directions (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!open.empty()) {
        Node* current = open.top();
        open.pop();

        int x = current->x;
        int y = current->y;

        // Mark visited
        closed[x][y] = true;

        // If goal reached
        if (x == goalX && y == goalY) {
            cout << "Path found:\n";
            printPath(current);
            return;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY) && grid[newX][newY] == 0 && !closed[newX][newY]) {

                Node* neighbor = new Node;
                neighbor->x = newX;
                neighbor->y = newY;

                neighbor->g = current->g + 1;
                neighbor->h = calculateH(newX, newY, goalX, goalY);
                neighbor->f = neighbor->g + neighbor->h;

                neighbor->parent = current;

                open.push(neighbor);
            }
        }
    }

    cout << "No Path Found\n";
}

// Main function
int main() {

    // 0 = free path, 1 = obstacle
    int grid[ROW][COL] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    int startX = 0, startY = 0;
    int goalX = 2, goalY = 3;

    aStar(grid, startX, startY, goalX, goalY);

    return 0;
}