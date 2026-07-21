#include <stdio.h>
int main()
{
    long long int k;
    int n;
    scanf("%lld%d", &k, &n);
    long long int array[n];
    for(int i =0;i<n;i++)
        scanf("%lld", &array[i]);
    long long int differences[n];
    long long int i;
    for( i = 0;i<n-1;i++)
    {
        differences[i] = array[i+1]- array[i];
    }
    differences[i] = (k-array[n-1])+array[0];
    long long int max = 0;
    for(long long int j = 0;j<n;j++)
    {
        if(differences[j]>max)
        {
            max = differences[j];
        }
    }
    printf("%lld", k-max);
    return 0;

}
