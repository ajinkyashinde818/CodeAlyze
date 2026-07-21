#include<stdio.h>
#include<algorithm>
using namespace std;
int x[100];
int y[100];
int r[100];
int main(){
    int a;
    while(scanf("%d",&a),a){
        for(int i=0;i<a;i++)scanf("%d%d%d",x+i,y+i,r+i);
        int b;
        scanf("%d",&b);
        for(int i=0;i<b;i++){
            int c,d,e,f;
            scanf("%d%d%d%d",&c,&d,&e,&f);
            bool ok=false;
            for(int j=0;j<a;j++){
                if((c-x[j])*(c-x[j])+(d-y[j])*(d-y[j])>=r[j]*r[j]||(e-x[j])*(e-x[j])+(f-y[j])*(f-y[j])>=r[j]*r[j]){
                    if((e-c)*(x[j]-c)+(f-d)*(y[j]-d)<0){
                        if((x[j]-c)*(x[j]-c)+(y[j]-d)*(y[j]-d)<=r[j]*r[j])ok=true;
                    }else{
                        if((e-c)*(x[j]-c)+(f-d)*(y[j]-d)>(e-c)*(e-c)+(f-d)*(f-d)){
                            if((x[j]-e)*(x[j]-e)+(y[j]-f)*(y[j]-f)<=r[j]*r[j])ok=true;
                        }else{
                            if((x[j]-c)*(x[j]-c)+(y[j]-d)*(y[j]-d)-((e-c)*(x[j]-c)+(f-d)*(y[j]-d))*((e-c)*(x[j]-c)+(f-d)*(y[j]-d))/((e-c)*(e-c)+(f-d)*(f-d))<=r[j]*r[j])ok=true;
                        }
                    }
                }
            }
            if(ok)printf("Safe\n");
            else printf("Danger\n");
        }
    }
}
