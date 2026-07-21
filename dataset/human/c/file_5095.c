#include <stdio.h>
int N;
int s[100001];
int d[100001];
int p[100001];


int Depth(int);
int Height(int);

int main() {
  int j,i;
  int id, l, r;
  scanf("%d", &N);

  for(i = 0; i < N; ++i) {
    p[i] = -1;
    s[i] = -1;
    d[i] = 0;
  }

  for(i = 0; i < N; i++) {
   

    scanf("%d %d %d", &id, &l, &r);

    if(l != -1) {
      p[l] = id;
      s[l] = r;
      d[id]++;
    }

    if(r != -1) {
      p[r] = id;
      s[r] = l;
      d[id]++;
    }
  }
  
  for(i = 0; i < N; ++i) {
    int depth = Depth(i);

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",   i, p[i], s[i], d[i], depth, Height(i));
    if(depth == 0) {
      printf("root\n");
    } else if(d[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}

int Depth(int i) {
  if(p[i] == -1){
    return 0;
  }
    return Depth(p[i]) + 1;
}

int Height(int i) {
  int j, h=0, temp;
  
  for(j = 0; j < N; ++j) {

    if(p[j] == i) {
      temp = Height(j) + 1;

      if(temp > h) h = temp;
    }
  }
  return h;
}
