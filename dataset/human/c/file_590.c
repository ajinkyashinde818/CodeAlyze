#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, m, lim, flag;
    char **np, **mp; 

    scanf("%d %d", &n, &m);

    np = malloc(sizeof(char *) * n);
    for(int i = 0; i < n; i++) np[i] = malloc(sizeof(char) * n + 1);

    mp = malloc(sizeof(char *) * m);
    for(int i = 0; i < n; i++) mp[i] = malloc(sizeof(char) * m + 1);

    for(int i = 0; i < n; i++) scanf("%s", np[i]);
    for(int i = 0; i < m; i++) scanf("%s", mp[i]);
    
    lim = n - m + 1;
    for(int i = 0; i < lim; i++){
        for(int j = 0; j < lim; j++){
            if(np[i][j] == mp[0][0]){
                flag = 0;
                for(int k = 0; k < m; k++){
                    for(int l = 0; l < m; l++){
                        if(np[i + k][j + l] != mp[k][l]){
                            flag = 1; 
                            break;
                        }
                    }
                    if(flag == 1) break;
                }
                if(flag == 0){
                    printf("Yes");
                    flag = 2;
                }
            }
            if(flag == 2) break;
        }
        if(flag == 2) break;
    }

    if(flag != 2) printf("No");
    return 0;
}
