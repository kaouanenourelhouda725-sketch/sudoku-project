#include <stdio.h>
int grid[9][9];
int i,j,row,col,n,val,ma_ja;
printf ("please enter the values of the sudoku grid(0 mean an emply cell)\n");
for (i=0;i<9;i++){
   for (j=0;j<9;j++){
        scanf ("%d",&grid[i][j]);
   }
}
while(1){
   printf("Current Sudoku Grid:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
   

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
