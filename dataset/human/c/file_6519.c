#include <stdio.h>

int main(){
    int N, Array[200001], max, minSub;
    scanf("%d\n",&N);
    for (int ix = 0 ; ix < N ; ix++)
        scanf("%d",&Array[ix]);
    max = Array[1] - Array[0];
    minSub = Array[0];
    for (int jx = 1 ; jx < N ; jx++){
        if (max < Array[jx] - minSub)
            max = Array[jx] - minSub;
        if ( minSub > Array[jx])
            minSub = Array[jx];
    }
  
  printf("%d\n",max);
  return 0;
}
