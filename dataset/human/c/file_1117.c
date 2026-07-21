#include <stdio.h>


int MCXI_val_2i(){
    char c=getchar();

    switch (c){
        case 'm':
            return 1000+MCXI_val_2i();
        case 'c':
            return 100+MCXI_val_2i();
        case 'x':
            return 10+MCXI_val_2i();
        case 'i':
            return 1+MCXI_val_2i();
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            int prefix=c-'0';
            char letter=getchar();

            switch (letter){
                case 'm':
                    return prefix*1000+MCXI_val_2i();
                case 'c':
                    return prefix*100+MCXI_val_2i();
                case 'x':
                    return prefix*10+MCXI_val_2i();
                case 'i':
                    return prefix+MCXI_val_2i();

            }

        }
        default:
            return 0;
    }
}


void output_i_MCXI(int val){
    int m=(val/1000)%10,c=(val/100)%10,x=(val/10)%10,i=val%10;

    if (m==0);
    else if (m==1)
        printf("m");
    else
        printf("%dm",m);

    if (c==0);
    else if (c==1)
        printf("c");
    else
        printf("%dc",c);

    if (x==0);
    else if (x==1)
        printf("x");
    else
        printf("%dx",x);

    if (i==0);
    else if (i==1)
        printf("i");
    else
        printf("%di",i);

    printf("\n");
}


int main() {
    int ln_num=0;
    scanf("%d\n",&ln_num);

    for (int i=0;i<ln_num;i++){
        int a,b;
        a=MCXI_val_2i();
       // getchar();
        b=MCXI_val_2i();
        //getchar();
        output_i_MCXI(a+b);

    }

    return 0;
}
