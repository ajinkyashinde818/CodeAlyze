#include <stdio.h>
#include <string.h>

int data;
char input1[15];
char input2[15];

void print_ans(int num);
int make(char data[]);

int main(void)
{
    int i, j, k;
    int num1, num2;
    scanf("%d",&data);
    for (k = 0; k < data; k++) {
        scanf("%s %s",input1, input2);
        num1 = make(input1);
        //printf("%d\n",num1);
        num2 = make(input2);
        //printf("%d\n",num2);
        print_ans(num1 + num2);
    }
    return 0;
}

int make(char data[]) 
{
    int i = 0, tmp = 1, ans = 0, len;
    len = strlen(data);
    while (i < len) {
        if ('0' <= data[i] && data[i] <= '9') {
            tmp = data[i] - '0';
            i++;
        } else if (data[i] == 'm') {
            ans += tmp * 1000;
            tmp = 1;
            i++;
        } else if (data[i] == 'c') {
            ans += tmp * 100;
            tmp = 1;
            i++;
        } else if (data[i] == 'x') {
            ans += tmp * 10;
            tmp = 1;
            i++;
        } else if (data[i] == 'i') {
            ans += tmp;
            tmp = 1;
            i++;
        }
    }
    return ans;
}

void print_ans(int num)
{
    int i, tmp, ket;
    while (num) {
        if (num >= 2000) {
            printf("%dm",num / 1000);
            num %= 1000;
        } else if (num >= 1000) {
            printf("m");
            num %= 1000;
        } else if (num >= 200) {
            printf("%dc",num / 100);
            num %= 100;
        } else if (num >= 100) {
            printf("c");
            num %= 100;
        } else if (num >= 20) {
            printf("%dx",num / 10);
            num %= 10;
        } else if (num >= 10) {
            printf("x");
            num %= 10;
        } else if (num >= 20) {
            printf("%dx",num / 10);
            num %= 10;
        } else if (num >= 10) {
            printf("x");
            num %= 10;
        } else if (num >= 2) {
            printf("%di",num / 1);
            num %= 1;
        } else if (num >= 1) {
            printf("i");
            num %= 1;
        }
    }
    puts("");
}
