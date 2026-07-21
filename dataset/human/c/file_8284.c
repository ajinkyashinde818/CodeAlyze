#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void print_int(int n)
{
    printf("%d\n",n);
}

void swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        while(j >= 0 && a[j+1] > a[j])
        {
            swap(&a[j+1],&a[j]);
            j--;
        }
        
    }
    
}

void print_list(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        print_int(a[i]);
    }
    
}



int main(void)
{
    int n,k;
    char s[10];

    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);

    char a = s[k-1];
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] != a)
            s[i] = '*';
    }
    printf("%s\n",s);

    
    
    return 0;

}
