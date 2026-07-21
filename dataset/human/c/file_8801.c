#include <stdio.h>

int h, w, cont=0, m[55][55];
char mat[55][55];
bool b=false;

void f(int i, int j){
    if(i < 0 || j < 0)
        return;
    if(i >= h || j >= w)
        return;
    if(mat[i][j] == '.')
        return;
    if(m[i][j] == 1 )
        return;
        //printf("%d %d\n", i, j);
        cont += 1;
        m[i][j] = 1;

    f(i, j+1);
    f(i+1, j);
    f(i, j-1);
    f(i-1, j);
}

void r(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(mat[i][j] == '#' && m[i][j]==0){
                cont = 0;
                f(i, j);
                //printf("%d %d %d\n", i, j, cont);
                if(cont == 1){
                    b = false;
                    break;
                }
            }
        }
        if(!b)
            break;
    }
}

int main(){
    scanf("%d%d", &h, &w);
    int x, y;
    for(int i=0; i<h; i++){
        scanf("%s", mat[i]);
        if(!b){
            for(int j=0; j<w; j++){
                if(mat[i][j] == '#'){
                    b = true;
                    x = i; y=j;
                }
            }
        }
    }
    b=true;
    r();

    if(!b)
        printf("No\n");
    else
        printf("Yes\n");
}
