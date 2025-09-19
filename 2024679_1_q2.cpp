#include <iostream>
using namespace std;

struct UniverseCoordinate {
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};

int main() {
    int height = 2, width = 2;

    UniverseCoordinate** grid = new UniverseCoordinate*[height];
    for (int r = 0; r < height; r++) {
        grid[r] = new UniverseCoordinate[width];
        for (int c = 0; c < width; c++) {
            grid[r][c] = {0, c + 1, r + 1, false};
        }
    }

    int snakeCount;
    cout << "How many snakes do you want to place? ";
    cin >> snakeCount;

    for (int s = 1; s <= snakeCount; s++) {
        int snakeId, x, y;
        cout << "\nEnter Snake ID: ";
        cin >> snakeId;
        cout << "Enter X coordinate: ";
        cin >> x;
        cout << "Enter Y coordinate: ";
        cin >> y;

        if (x > width || y > height) {
            int newHeight = max(height, y);
            int newWidth = max(width, x);

            UniverseCoordinate** updatedGrid = new UniverseCoordinate*[newHeight];
            for (int r = 0; r < newHeight; r++) {
                updatedGrid[r] = new UniverseCoordinate[newWidth];
                for (int c = 0; c < newWidth; c++) {
                    if (r < height && c < width)
                        updatedGrid[r][c] = grid[r][c];
                    else
                        updatedGrid[r][c] = {0, c + 1, r + 1, false};
                }
            }
            for (int r = 0; r < height; r++) {
                delete[] grid[r];
            }
            delete[] grid;

            grid = updatedGrid;
            height = newHeight;
            width = newWidth;
        }
        grid[y - 1][x - 1].is_snake = true;
        grid[y - 1][x - 1].s_number = snakeId;
    }
    cout << "\n--- Universe Snapshot ---\n";
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cout << "(" << grid[r][c].x_position << "," << grid[r][c].y_position << ") ";
            if (grid[r][c].is_snake)
                cout << "Snake #" << grid[r][c].s_number;
            else
                cout << "Empty";
            cout << endl;
        }
    }
    for (int r = 0; r < height; r++) {
        delete[] grid[r];
    }
    delete[] grid;

    return 0;
}