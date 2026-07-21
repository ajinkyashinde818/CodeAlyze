//
//  main.c
//  Numeral System
//
//  Created by x15071xx on 2016/06/09.
//  Copyright ?? 2016??´ AIT. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int n,i,j,k;
    
    scanf("%d",&n);
    
    for (i=0; i<n; i++) {
        
        char mcxi1[9]={0},mcxi2[9]={0},add[9]={0};
        int sum=0,scalar=0,x = 0;
        unsigned int count;
        scanf("%s %s",mcxi1,mcxi2);
        
        //?????????????????´??°????±???????
        for (j=0; j<strlen(mcxi1); j++) {
            if (mcxi1[j] >=97 && mcxi1[j] <= 122) {
                if (mcxi1[j-1] >= 48 && mcxi1[j-1] <= 57) {
                    scalar = mcxi1[j-1] - 48;
                } else {
                    scalar = 1;
                }
                if (mcxi1[j] == 'm') {
                    sum += scalar * 1000;
                }
                if (mcxi1[j] == 'c') {
                    sum += scalar * 100;
                }
                if (mcxi1[j] == 'x') {
                    sum += scalar * 10;
                }
                if (mcxi1[j] == 'i') {
                    sum += scalar * 1;
                }
            }
        }
        for (j=0; j<strlen(mcxi2); j++) {
            if (mcxi2[j] >=97 && mcxi2[j] <= 122) {
                if (mcxi2[j-1] >= 48 && mcxi2[j-1] <= 57) {
                    scalar = mcxi2[j-1] - 48;
                } else {
                    scalar = 1;
                }
                
                if (mcxi2[j] == 'm') {
                    sum += scalar * 1000;
                }
                
                if (mcxi2[j] == 'c') {
                    sum += scalar * 100;
                }
                if (mcxi2[j] == 'x') {
                    sum += scalar * 10;
                }
                if (mcxi2[j] == 'i') {
                    sum += scalar * 1;
                }
            }
        }
        //??´??°????????????????????????
        if (sum/1000 >= 1) {
            x = sum / 1000;
            sum -= x * 1000;
            if (x == 1) {
                add[0] = 'm';
            } else if (x > 1) {
                add[0] = x + 48;
                add[1] = 'm';
            }
        }
        
        if (sum/100 >= 1) {
            x = sum / 100;
            sum -= x * 100;
            count = strlen(add);
            if (x == 1) {
                add[count] = 'c';
            } else if (x > 1) {
                add[count] = x + 48;
                add[count+1] = 'c';
            }
        }
        
        if (sum/10 >= 1) {
            x = sum / 10;
            sum -= x * 10;
            count = strlen(add);
            if (x == 1) {
                add[count] = 'x';
            } else if (x > 1) {
                add[count] = x + 48;
                add[count+1] = 'x';
            }
        }
        
        if (sum >= 1) {
            count = strlen(add);
            if (sum == 1) {
                add[count] = 'i';
            } else if (sum > 1){
                add[count] = sum + 48;
                add[count+1] = 'i';
            }
        }
        
        //??°???
        printf("%s\n",add);
    }
    
    return 0;
}
