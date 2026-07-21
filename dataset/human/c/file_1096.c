#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dec(char text[]){
    int sum = 0;
    int i=0;

    while(text[i] != '\0'){
        if(text[i] >= 50 && text[i] <= 57){
            if((text[i+1]) == 'm'){
                sum += (1000 * ((text[i])-48));
                i++;
            }else if(text[i+1] == 'c'){
                sum += (100 * (text[i]-48));
                i++;
            }else if(text[i+1] == 'x'){
                sum += (10 * (text[i]-48));
                i++;
            }else{
                sum += (text[i])-48;
                i++;
            }
        }

        else{
            if(text[i] == 'm'){
                sum += 1000;
            }else if(text[i] == 'c'){
                sum += 100;
            }else if(text[i] == 'x'){
                sum += 10;
            }else{
                sum += 1;
            }
        }

        i++;
    }

    return sum;
}

int main(){

    int i,n;
    int a;
    int d;
    char input[2][10];
    char output[10];

    scanf("%d",&n);

    for(i=0;i<n;i++){
        a=0;
        d=1000;
        output[0]='\0';

        scanf("%s %s",input[0],input[1]);

        a = dec(input[0]);
        a += dec(input[1]);

        while(d){
            if(a/d >1){
                switch(d){
                    case 1000: sprintf(output,"%s%dm",output,a/d);  break;
                    case 100: sprintf(output,"%s%dc",output,a/d);  break;
                    case 10: sprintf(output,"%s%dx",output,a/d);  break;
                    case 1: sprintf(output,"%s%di",output,a/d);  break;
                }
            }else if(a/d == 1){
                switch(d){
                    case 1000: sprintf(output,"%sm",output);  break;
                    case 100: sprintf(output,"%sc",output);  break;
                    case 10: sprintf(output,"%sx",output);  break;
                    case 1: sprintf(output,"%si",output);  break;
                }
            }
            a %= d;
            d /= 10;
        }

        printf("%s\n",output);
           
    }



    return 0;
}
