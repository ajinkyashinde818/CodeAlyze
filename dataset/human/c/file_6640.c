#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int ReadValue() {
    int value; 
    scanf("%d",&value); 
    return value;
}
void ReadArray(int R[],int n) {
    int i; 
    for (i=0; i<n; i++) {
        scanf("%d",&R[i]);
    } 
}
int main() {
    int n=ReadValue();
    int R[n]; ReadArray(R,n);
    int maxR=R[1]-R[0],minR=R[0];
    for (int i=1; i<n; i++) {
        maxR=max(maxR,R[i]-minR);
        minR=min(minR,R[i]);
    }
    printf("%d\n",maxR);
    return 0;
}
