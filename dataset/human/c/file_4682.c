#include<stdio.h>

int rei[100001];
int sub[100001];
int fin[100001];
int n;

int depth(int);
int height(int);

int main(int argc,char *argv[]){
  int i,j;
  scanf("%d",&n);
  for(i = 0;i < n; ++i){
    rei[i] = -1;
    sub[i] = -1;
    fin[i] = 0;
  }
  for(i = 0; i < n; ++i){
    int ts, hi, mi;
    scanf("%d %d %d", &ts,&hi,&mi);
    if(hi != -1) {
      rei[hi] = ts;
      sub[hi] = mi;
      fin[ts]++; 
    }
    if(mi != -1) {
      rei[mi] = ts;
      sub[mi] = hi;
      fin[ts]++;
    }
  }
  
  for(i = 0; i < n; ++i) {
    int deg = depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   i, rei[i], sub[i], fin[i], deg, height(i));
    if(deg == 0) {
      printf("root\n");
    } else if(fin[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}

int depth(int i) {
  if (rei[i] == -1)return 0;
  return depth(rei[i]) + 1;
}

int height(int i){
  int j, p = 0;
  
  for (j = 0; j < n; ++j) {
    if (rei[j] == i){
    int t = height(j) + 1;
    if(t > p) p = t;
  }
}
return p;
}
