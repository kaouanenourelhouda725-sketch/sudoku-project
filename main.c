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
