#include <stdio.h>
int grid[9][9];
int i,j,row,col,n,full,ma_ja;
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
    full = 1;
    if (full == 1) {
        printf("the soduko grid is complete\n");
        break;
    }
    for(i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (grid[i][j] == 0)
                full = 0;
        }
    }
     printf("Enter row number (1-9) or (q:to quit): \n");
    scanf("%d", &row);
    if (row == "q")
        break;

    printf("Enter column number (1-9): \n");
    scanf("%d", &col);

    printf("Enter number (1-9): ");
    scanf("%d", &n);
    row--;
    col--;
if (row < 0  row > 8  col < 0  col > 8  n< 1 || n > 9) {
        printf(" Invalid input \n");
        continue;
    }
    if (grid[row][col] != 0) {
        printf(" This cell is already filled \n");
        continue;
    }

   
if (row < 0  row > 8  col < 0  col > 8  n< 1 || n > 9) {
        printf(" Invalid input \n");
        continue;
    }
    if (grid[row][col] != 0) {
        printf(" This cell is already filled \n");
        continue;
    }
valid = 1;
    for (i = 0; i < 9; i++)
        if (grid[row][i] == n)
            valid = 0;
    for (i = 0; i < 9; i++)
        if (grid[i][col] == n)
            valid = 0;
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == n)
                valid = 0;

    if (valid == 1) {
        grid[row][col] = n;
        printf(" Number placed successfully\n");
    } else {
        printf(" Number violates Sudoku rules\n");
    }
}
