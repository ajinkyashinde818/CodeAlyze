#include <stdio.h>
#define N 25

typedef struct{

  int parent;
  int left;
  int right;

      }Node;

      int n;
Node in[N];

void init();
int sibling(int);
int depth(int);
int type(int);
int degree(int);
int height(int);

int main(){

  int i, id;

   init();

        scanf("%d", &n);

            for(i = 0; i < n; i++){
    scanf("%d", &id);
    scanf("%d %d", &in[id].left, &in[id].right);

          if(in[id].left == -1 && in[id].right == -1) continue;

                in[in[id].left].parent = id;
    in[in[id].right].parent = id;
    }

                for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ", i, in[i].parent, sibling(i));
    printf("degree = %d, depth = %d, height = %d, ", degree(i), depth(i), height(i));

    if(type(i) == 0){
      printf("root\n");
    } else if(type(i) == 1){
      printf("leaf\n");
    } else if(type(i) == 2){
      printf("internal node\n");
    }
                }
  return 0;
}

int depth(int num){
  int i;

    for(i = 0; in[num].parent != -1; i++){
      num = in[num].parent;
    }

         return i;
}

void init(){
  int i;

   for(i = 0; i < N; i++){
    in[i].parent = -1;
    in[i].left = -1;
    in[i].right = -1;
    }

        }




int type(int num){

  if(in[num].parent == -1){
   return 0;
    }

    if(in[num].left == -1 && in[num].right == -1){
    return 1;
    }

        return 2;

            }

int height(int num){
  int i;
  int heightLeft = -1, heightRight = -1;

      if(in[num].left != -1){
    heightLeft = height(in[num].left);
    }

          if(in[num].right != -1){
    heightRight = height(in[num].right);
    }

          heightLeft++;
          heightRight++;

          if(heightLeft > heightRight){
            return heightLeft;
          } else {
            return heightRight;
          }

}

int sibling(int num){

  if(in[num].parent == -1){
    return -1;
    }

    if(in[in[num].parent].left == num){
    return in[in[num].parent].right;
    } else {
    return in[in[num].parent].left;
    }

        }

int degree(int num){

  if(in[num].left == -1 && in[num].right == -1){
   return 0;
    }

    if(in[num].left == -1 || in[num].right == -1){
    return 1;
    }

        return 2;

             }
