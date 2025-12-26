#include <stdio.h>

int grid[9][9] = {
    {3,0,6,5,0,8,4,0,0},
    {5,2,0,0,0,0,0,0,0},
    {0,8,7,0,0,0,0,3,1},
    {0,0,3,0,1,0,0,8,0},
    {9,0,0,8,6,3,0,0,5},
    {0,5,0,0,9,0,6,0,0},
    {1,3,0,0,0,0,2,5,0},
    {0,0,0,0,0,0,0,7,4},
    {0,0,5,2,0,6,3,0,0}
};

int isValid(int row, int col, int num) {
    int i, j;

    for (i = 0; i < 9; i++) {
        if (grid[row][i] == num)
            return 0;
        if (grid[i][col] == num)
            return 0;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

int solve() {
    int row, col, num;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;

                        if (solve())
                            return 1;

                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;

    if (solve()) {
        printf("Sudoku Solved:\n");
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found\n");
    }

    return 0;
}
