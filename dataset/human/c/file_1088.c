#include <stdio.h>
#include <string.h>

int rev(char *s){
    int i,j;
    int sum = 0;

        if(s[0] == 'm')
            sum+=1000;
        if(s[0] == 'c')
            sum+=100;
        if(s[0] == 'x')
            sum+=10;
        if(s[0] == 'i')
            sum+=1;


    for(i = 1; i < strlen(s); i++){
        if(s[i] == 'm'){
            if(s[i-1] >= '2' && s[i-1] <= '9'){
                sum += 1000*(s[i-1] - '0');
            }else{
                sum+=1000;
            }
        }
        if(s[i] == 'c'){
            if(s[i-1] >= '2' && s[i-1] <= '9'){
                sum += 100*(s[i-1] - '0');
            }else{
                sum+=100;
            }
        }
        if(s[i] == 'x'){
            if(s[i-1] >= '2' && s[i-1] <= '9'){
                sum += 10*(s[i-1] - '0');
            }else{
                sum+=10;
            }
        }
        if(s[i] == 'i'){
            if(s[i-1] >= '2' && s[i-1] <= '9'){
                sum += 1*(s[i-1] - '0');
            }else{
                sum+=1;
            }
        }
    }

    return sum;
}



int main(){
    
    char mcxi1[10], mcxi2[10],mcxi3[10];
    int n,i,j;

    int x1,x2,x3;

    scanf("%d",&n);

    while(n > 0){
        x1 = 0;x2 = 0;

        scanf("%s %s",mcxi1,mcxi2);
        
        x1 = rev(mcxi1);
        x2 = rev(mcxi2);
        /*
        printf("%d\n",x1);

        printf("%d\n",x2);
        */
        x3 = x1+x2;

        int k=1000;
        while(k>0){
            int d=x3/k;
            if(d>=1){
                if(d>=2)printf("%d",d);
                if(k==1000)printf("m");
                if(k==100)printf("c");
                if(k==10)printf("x");
                if(k==1)printf("i");
            }
            x3%=k;
            k/=10;
        }
        printf("\n");
    

        n--;    
    }


    return 0;

}
