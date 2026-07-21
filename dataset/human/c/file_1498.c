#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

typedef long long ll;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

/*qsort(array,num_of_index,sizeof(int),compare_int); */
 int compare_int(const void *a,const void *b){
     return *(int*) a - *(int *) b; 
 } 
 
int b_search(int* array,int left,int right,int key){
    int mid = left - (right - left)/2;
     if( right - left == 1){
         if(array[mid]==key)
             return mid;
          else
               return -1;
     }
     if(array[mid]==key)
         return mid;
     else if(array[mid]>key)
         b_search(array,left,mid,key);
     else if(array[mid]<key)
         b_search(array,mid,right,key);
}

/*lower_bound(key以上のイテレータを返す)*/
 /*例えば,2,2,5,5,9でkey=2なら(2),2,5,5,9を返す*/
 int lower_bound(int  *array,int left,int right,int key){
     if(right-left==1)
         return left;
     int mid = left + (right - left)/2;
     if(array[mid]<key)
         return lower_bound(array,mid,right,key);
     else
         return lower_bound(array,left,mid,key);
 }

int main(){
    char X,Y;
    scanf("%c %c",&X,&Y);
    if(X>Y) printf(">");
    else if(X<Y) printf("<");
    else printf("=");
}
