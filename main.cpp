#include"myStack.h"
#include<fstream>

int main() {

    ifstream fin;
    fin.open("input.txt");

    int rows = 0, cols = 0;

    fin >> rows >> cols;

    int** Matrix = new int* [rows];
    for (int I = 0; I < rows; ++I)
        Matrix[I] = new int[cols];

    for (int I = 0; I < rows; ++I)
        for (int j = 0; j < cols; ++j)
            fin >> Matrix[I][j];

    cout << "Given Maze Path:" << endl;
    for (int I = 0; I < rows; ++I) {
        for (int j = 0; j < cols; ++j) {
            cout<< Matrix[I][j] << " ";
        } cout << endl;
    }

    myStack<int> rowpath(100);
    myStack<int> colpath(100);

    int x = 0, y = 0;
    Matrix[x][y] = -1;

    while (!(x == rows - 1 && y == cols - 1)) {
        bool moved = false;

        if (x - 1 >= 0 && Matrix[x - 1][y] == 1) {
            x--;
            rowpath.push(-1);
            colpath.push(0);
            Matrix[x][y] = -1;
            moved = true;
        }
        else if (x + 1 < rows && Matrix[x + 1][y] == 1) {
            x++;
            rowpath.push(1);
            colpath.push(0);
            Matrix[x][y] = -1;
            moved = true;
        }
        else if (y + 1 < cols && Matrix[x][y + 1] == 1) {
            y++;
            rowpath.push(0);
            colpath.push(1);
            Matrix[x][y] = -1;
            moved = true;
        }
        else if (y - 1 >= 0 && Matrix[x][y - 1] == 1) {
            y--;
            rowpath.push(0);
            colpath.push(-1);
            Matrix[x][y] = -1;
            moved = true;
        }
       
        if (!moved) {
            if (!rowpath.isEmpty() && !colpath.isEmpty()) {
                x += rowpath.pop();
                y += colpath.pop();
            }
            else {
                cout << "\nPath not found." << endl;
                return 0; 
            }
        }

    }

    cout << "\nSolved Maze Path:\n";
    for (int I = 0; I < rows; ++I)
        for (int j = 0; j < cols; ++j)
            Matrix[I][j] = 0;

    x = y = 0;
    Matrix[x][y] = 1;
    myStack<int> reverserowPath(100);
    myStack<int> reversecolPath(100);
    while (!rowpath.isEmpty())
        reverserowPath.push(rowpath.pop());

    while (!colpath.isEmpty())
        reversecolPath.push(colpath.pop());

    while (!(reverserowPath.isEmpty() && reversecolPath.isEmpty())) {

        x += reverserowPath.pop();
        y += reversecolPath.pop();
        Matrix[x][y] = 1;
    }

    ofstream fout("output.txt");
    for (int I = 0; I < rows; ++I) {
        for (int j = 0; j < cols; ++j) {
            cout << Matrix[I][j] << " ";
            fout << Matrix[I][j] << " ";
        }
        cout << endl;
        fout << endl;
    }

    fout.close();
    return 0;
}