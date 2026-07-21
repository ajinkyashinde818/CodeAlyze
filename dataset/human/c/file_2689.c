#include <stdio.h>

int main(){
    int k, s;
    int count=0;
    scanf("%d %d", &k, &s);
    for(int x=0;x<=k;x++)
    {
        //if(x>s) break;
        for(int y=0;y<=x;y++)
        {
            //if(x+y>s) break;
            for(int z=0;z<=y;z++)
            {
                //if(x+y+z>s) break;
                if(x+y+z==s){
                    if(x==y&&y==z) count+=1;
                    else if(x!=y&&y!=z&&z!=x) count+=6;
                    else count+=3;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
