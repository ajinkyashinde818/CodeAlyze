//
//  main.c
//  cimple_calculator
//
//  Created by aiba1994 on 2016/05/13.
//  Copyright ?? 2016??´ aiba1994. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 10013
    // 10014
    // Print a Frame
    int w, h;
    int i, j;
    
    while (1) {
        scanf("%d %d", &h, &w);
        
        if(h==0 && w==0){
            break;
        }
        
        for (i=0; i<h; i++) {
            for (j=0; j<w; j++) {
                // if(j== 0 || j==w-1 ||i==0 || i==h-1){
                if ((i%2==0&&j%2==0)||(i%2==1&&j%2==1)) {
                    
                   printf("#");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
    
    /*
    // 10012
    // Print a Rectangle
    int h, w;
    int i,j;
    
    while (1) {
        scanf("%d %d", &h, &w);
        
        if(h==0 && w==0){
            break;
        }
        
        for (i=0; i<h; i++) {
            for (j=0; j<w; j++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
     */
    
    /*
    // 10016
    // Grading
    int m, f, r; // m, f ??? 50 r ??? 100
    
    // ????¨????????????????????????´???????????°??? -1
    while (1) {
        scanf("%d %d %d", &m, &f, &r);
        if(m==-1&&f==-1&&r==-1)break;
        if(m==-1||f==-1){
            printf("F\n");
        }else if(m+f>=80){
            printf("A\n");
        }else if(m+f>=65){
            printf("B\n");
        }else if(m+f>=50){
            printf("C\n");
        }else if(m+f>=30){
            if(r>=50){
                printf("C\n");
            }else{
                printf("D\n");
            }
        }else{
            printf("F\n");
        }
    }
    */
    
    /*
    // 10010
    int a[]={}, b[]={};
    char op[] = {};
    
    int i=0;
    
    while (1) {
        scanf("%d %s %d", &a[i], &op[i], &b[i]);
        
        if (op[i] == '?') {
            break;
        }
        i++;
    }
    
    for (int j=0; j<i; j++) {
        switch (op[j]) {
        case '+':
            printf("%d\n", a[j]+b[j]);
            break;
        case '-':
            printf("%d\n", a[j]-b[j]);
            break;
        case '*':
            printf("%d\n", a[j]*b[j]);
            break;
        case '/':
            printf("%d\n", a[j]/b[j]);
            break;
        default:
            break;
        }
    }
    */
    
    /*
    // 10008
    int a,b;
    int d,r;
    double f;
    
    scanf("%d %d", &a, &b);
    
    d = a/b;
    r = a%b;
    f = (double)a/b;
    
    printf("%d %d %lf\n",d,r,f);
    
     */
    
    // 10004
    /*
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    int i,j,temp;
    
    for(i=0; i<3; i++){
        for(j=3-1; j>i; j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    
    printf("%d %d %d\n", a[0], a[1], a[2]);
    */
    return 0;
}
