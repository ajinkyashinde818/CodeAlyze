#include <stdio.h>
#include <limits.h>

int main(void) {
   
   int H,W,K;
   
   scanf("%d %d %d",&H,&W,&K);
   
   char S[H][W];
   int Ans[H][W];
   int i,j,k;
   int str = 1;
   
   for (i = 0; i < H; i++) {
      scanf("%s",S[i]);
      for (j = 0; j < W; j++) {
         if (S[i][j] == '#') {
            Ans[i][j] = str;
            str++;
         }
         else {
            Ans[i][j] = 0;
         }
      }
   }
   
   int Col[W];
   int col_num;
   
   for (i = 0; i < H; i++) {
      col_num = 0;
      for (j = 0;j < W; j++) {
         Col[j] = -1;
      }
      
      for (j = 0; j < W; j++) {
         if (Ans[i][j] != 0) {
            Col[col_num] = j;
            col_num++;
         }
      }
      
      if (col_num == 1) {
         for (k = 0; k < W; k++) {
            Ans[i][k] = Ans[i][Col[0]];
         }
      }
      else {
         
         for (k = 0; k < Col[0]; k++) {
            Ans[i][k] = Ans[i][Col[0]];
         }

         for (j = 1; j < col_num; j++) {
            for (k = Col[j - 1]; k < Col[j]; k++) {
               Ans[i][k] = Ans[i][Col[j - 1]];
            }
         }
         
         for (k = Col[col_num - 1]; k < W; k++) {
            Ans[i][k] = Ans[i][Col[col_num - 1]];
         }
         
      }
   }
   
   for (i = 0; i < H; i++) {
      if (Ans[i][0] == 0) {
         
         int row = i;
         
         while (Ans[row][0] == 0 && row < H) {
            row++;
         }
         
         if (row == H) {
            row = i;
            while (Ans[row][0] == 0 && row < H) {
               row--;
            }
         }
         
         for (j = 0; j < W; j++) {
            Ans[i][j] = Ans[row][j];
         }
   
      }
   }
   
   
   
   for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
         printf("%d ",Ans[i][j]);
      }
      printf("\n");
   }
   
   
   
   
   
   return 0;
}
