#include <iostream>
#include <ctime>

using namespace std;

const int rows = 4;
const int cols = 4;

int maxShips = 10;

int matrix[rows][cols];

void clear() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

void show() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int numberOfShips() {

    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) count++;
        }
    }

    return count;
}

void setShips() {
    
    int i = 0;

    while (i < maxShips) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (matrix[x][y] != 1) {
            matrix[x][y] = 1;
            ++i;
        }
    }
}

bool attack(int x, int y) {
    if (matrix[x][y] == 1) {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int main() {

    clear();
    setShips();

    int pos1, pos2;
    string prompt;

    while (true) {
        cout << "Please input location: ";
        cin >> pos1 >> pos2;
        if (attack(pos1, pos2)) {
            cout << "You got me!" << endl;
        }
        else {
            cout << "Sorry! No ships at that position!" << endl;
        }

        cout << "Number of ships left: " << numberOfShips() << endl;
        cout << "Do you want to surrender (y/n): ";
        cin >> prompt;
        if (prompt == "y") break;
    }

    cout << "Game over!" << endl;
    show();
    return 0;
}