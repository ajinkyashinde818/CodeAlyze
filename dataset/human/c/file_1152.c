#include<stdio.h>
#include<string.h>
void i_sort(char a[],int b){
    int i,j,temp;
    for(i=1;i<b;i++){
        for(j=i;j>0&&a[j]<a[j-1];j--){
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
void i2_sort(char a[],int b){
    int i,j,temp;
    for(i=1;i<b;i++){
        for(j=i;j>0&&a[j]>a[j-1];j--){
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
int main()
{
	int i,f=0,l,l2;
	char s[100],t[100];
	scanf("%s\n%s",s,t);
	l=strlen(s);
	l2=strlen(t);
	i_sort(s,l);
	i2_sort(t,l2);
	for(i=0;i<l&&i<l2;i++){
		if(s[i]>t[i]){ 
			f=1;
			break;
		}
		else if(s[i]==t[i]) f=2;
		else {
			f=0;
			break;
		}
	}
	if(f==2&&l2>l) f=0;
	if(f==0) printf("Yes\n");
	else printf("No\n");
	return 0;
}
