#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

const int arrRow = 40;

const int arrColumn = 40;

int Newgrid[arrRow][arrColumn];

void Nextgen(int grid[arrRow][arrColumn])

{

    int temp = 0;

    for (int c = 0;c < arrRow;c++) {

        for (int d = 0;d < arrColumn;d++) {

            temp = 0;
            if (grid[c - 1][d] == 1) {//corner1
                temp++;
            }

            if (grid[c - 1][d - 1] == 1) {//corner2
                temp++;
            }

            if (grid[c + 1][d - 1] == 1) {//corner3
                temp++;
            }

            if (grid[c + 1][d + 1] == 1) {//corner4
                temp++;
            }

            if (grid[c][d - 1] == 1) {//corner5
                temp++;
            }

            if (grid[c][d + 1] == 1) {//corner6
                temp++;
            }

            if (grid[c - 1][d + 1] == 1) {//corner7
                temp++;
            }

            if (grid[c + 1][d] == 1) {//corner8
                temp++;
            }

            /*Newgrid*/

            Newgrid[c][d] = 0;

            if (grid[c][d] == 0 && temp == 3) {//rule1 Dead cell becomes a live cell

                Newgrid[c][d] = 1;
            }

            else if (grid[c][d] == 1 && temp > 3) {//rule2 live cell becomes dead cell.

                Newgrid[c][d] = 0;
            }

            else if (grid[c][d] == 1 && temp < 2) {//live cellbecomes deadcell.

                Newgrid[c][d] = 0;
            }

            else if (grid[c][d] == 1 && (temp == 2 || temp == 3)) {//rule3 repopulation

                Newgrid[c][d] = 1;
            }

        }

    }

}

void copytoNew(int grid[arrRow][arrColumn]) {
  
    for (int f = 0;f < arrRow;f++) {

        for (int g = 0;g < arrColumn;g++) {

            grid[f][g] = Newgrid[f][g];

            cout << grid[f][g] << " ";

        }

        cout << "\n";

    }
    

}


int main() {

    int grid[arrRow][arrColumn];

    for (int i = 0;i < arrRow;i++) {

        for (int j = 0;j < arrColumn;j++) {

            grid[i][j] = 0;

        }

    }
    
    grid[3][5] = 1;
    grid[4][4] = 1;
    grid[5][7] = 1;
    grid[6][3] = 1;
    grid[4][6] = 1;
    grid[5][5] = 1;
    grid[3][6] = 1;
    grid[3][5] = 1;
    grid[15][1] = 1;
    grid[15][30] = 1;
    grid[15][28] = 1;
    grid[14][29] = 1;
    grid[4][8] = 1;
    grid[7][5] = 1;
    grid[7][6] = 1;
    grid[9][1] = 1;
    grid[9][2] = 1;
    grid[8][8] = 1;
    grid[3][8] = 1;
    grid[4][3] = 1;
    grid[7][2] = 1;
    grid[8][5] = 1;
    grid[5][6] = 1;
    grid[9][4] = 1;
    grid[8][4] = 1;
    grid[10][2] = 1;
    grid[11][3] = 1;
    grid[12][4] = 1;
    grid[11][1] = 1;
    grid[8][3] = 1;
    grid[8][4] = 1;


   
    while (true) {
        
            system("cls");
            Sleep(1000);
            Nextgen(grid);
            copytoNew(grid);
            Sleep(1000);

     

    }

   
    
    return 0;

}
