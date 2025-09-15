#include <iostream>
using namespace std;

struct UniverseCoordinate {
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};

int main() {
    int rows = 2, cols = 2;
    UniverseCoordinate** UniverseData = new UniverseCoordinate*[rows];
    for (int i = 0; i < rows; i++) {
        UniverseData[i] = new UniverseCoordinate[cols];
        for (int j = 0; j < cols; j++) {
            UniverseData[i][j] = {0, j+1, i+1, false};
        }
    }

    int n;
    cout << "Enter number of snakes: ";
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int x, y, num;
        cout << "\nEnter Snake Number: ";
        cin>>num;
        cout << "\nEnter x coordinate: ";
        cin>>x;
        cout << "\nEnter y coordinate: ";
        cin>>y;

        if (x > cols || y > rows) {
            int newRows = max(rows, y);
            int newCols = max(cols, x);

            UniverseCoordinate** NewData = new UniverseCoordinate*[newRows];
            for (int i = 0; i < newRows; i++) {
                NewData[i] = new UniverseCoordinate[newCols];
                for (int j = 0; j < newCols; j++) {
                    if (i < rows && j < cols)
                        NewData[i][j] = UniverseData[i][j];
                    else
                        NewData[i][j] = {0, j+1, i+1, false};
                }
            }

            for (int i = 0; i < rows; i++) {
                delete[] UniverseData[i];
            }
            delete[] UniverseData;

            UniverseData = NewData;
            rows = newRows; cols = newCols;
        }

        UniverseData[y-1][x-1].is_snake = true;
        UniverseData[y-1][x-1].s_number = num;
    }

    cout << "\nFinal Universe:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "(" << UniverseData[i][j].x_position << "," << UniverseData[i][j].y_position << ") ";
            if (UniverseData[i][j].is_snake) cout << "Snake #" << UniverseData[i][j].s_number;
            else cout << "No Snake";
            cout << endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] UniverseData[i];
    }
    delete[] UniverseData;

    return 0;
}
