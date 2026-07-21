#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

int k,n;
int *a;
char line[10000000];
char space[] = " ";

if(fgets(line,sizeof(line),stdin)!=NULL){}
sscanf(line,"%d%d",&k,&n);

a = (int *)malloc(sizeof(int)*n);

if(fgets(line,sizeof(line),stdin)!=NULL){}

int i;
int max_distance = 0;
char *temp;
temp = strtok(line,space);
for(i=0;i<n;i++){
  a[i] = atoi(temp);
  temp = strtok(NULL,space);
  if(i!=0){
    if(a[i]-a[i-1]>max_distance){
      max_distance = a[i] - a[i-1];
    }
  }
}

if(k-a[n-1]+a[0] > max_distance){
  max_distance = k - a[n-1]+a[0];
}

printf("%d",k-max_distance);
return 0;

}
