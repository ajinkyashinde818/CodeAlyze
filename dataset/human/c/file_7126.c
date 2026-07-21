#include<stdio.h>
int main(void)
{
  int a,b,i,j;

  for(;;){
    scanf("%d %d",&a,&b);

    if(a==0 && b==0)
      break;

    switch(b%2){
      case 0:
        if(a%2==0){
          for(j=1;j<=a/2;j++){
            for(i=1;i<=b/2;i++)
              printf("#.");
            printf("\n");
            for(i=1;i<=b/2;i++)
              printf(".#");
            printf("\n");
          }
        }else{
          for(j=1;j<=(a-1)/2;j++){
            for(i=1;i<=b/2;i++)
              printf("#.");
            printf("\n");
            for(i=1;i<=b/2;i++)
              printf(".#");
            printf("\n");
          }
          for(i=1;i<=b/2;i++)
            printf("#.");
          printf("\n");
        }

        printf("\n");  break;

      case 1:
        if(a%2==0){
          for(j=1;j<=a/2;j++){
            for(i=1;i<=(b-1)/2;i++)
              printf("#.");
            printf("#\n");
            for(i=1;i<=(b-1)/2;i++)
              printf(".#");
            printf(".\n");
          }
        }else{
          for(j=1;j<=(a-1)/2;j++){
            for(i=1;i<=(b-1)/2;i++)
              printf("#.");
            printf("#\n");
            for(i=1;i<=(b-1)/2;i++)
              printf(".#");
            printf(".\n");
          }
          for(i=1;i<=(b-1)/2;i++)
            printf("#.");
          printf("#\n");
	}

        printf("\n");  break;
    }
  }

  return 0;
}
