#include<iostream>
#include<stdio.h>
int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int max = 0;
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    max = arr[0] + (k - arr[n - 1]);
    for (int i = 0; i < n - 1; i++)
    {
      if(max < arr[i + 1] - arr[i])
      {
        max = arr[i + 1] - arr[i];
      }
    }
    printf("%d", k - max);
}
