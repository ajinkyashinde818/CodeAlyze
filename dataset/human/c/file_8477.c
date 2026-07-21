#include<stdio.h>

int main(){
    int H,i,j,P[10][5],Q[10][5],S,a,b;
    for(;scanf("%d",&H),H;){
        S=0;
        for(i=0;i<10;i++)for(j=0;j<5;j++)P[i][j]=-1;
        for(i=0;i<10;i++)for(j=0;j<5;j++)Q[i][j]=-1;
        
        for(i=10-H;i<10;i++)scanf("%d %d %d %d %d",&P[i][0],&P[i][1],&P[i][2],&P[i][3],&P[i][4]);
        
        //for(i=0;i<10;i++){for(j=0;j<5;j++)printf("%d ",P[i][j]);printf("\n");}
        b=0;
        for(;b==0;){
            b=1;
        for(i=0;i<10;i++)if(P[i][0]==P[i][1]&&P[i][0]==P[i][2]&&P[i][0]==P[i][3]&&P[i][0]==P[i][4]&&P[i][0]!=-1){
            S+=P[i][0]*5;
            P[i][0]=-1; P[i][1]=-1; P[i][2]=-1; P[i][3]=-1; P[i][4]=-1;
        }
        for(i=0;i<10;i++)if(P[i][0]==P[i][1]&&P[i][0]==P[i][2]&&P[i][0]==P[i][3]&&P[i][0]!=-1){
            S+=P[i][0]*4;
            P[i][0]=-1; P[i][1]=-1; P[i][2]=-1; P[i][3]=-1;
        }
        for(i=0;i<10;i++)if(P[i][0]==P[i][1]&&P[i][0]==P[i][2]&&P[i][0]!=-1){
            S+=P[i][0]*3;
            P[i][0]=-1; P[i][1]=-1; P[i][2]=-1;
        }
        for(i=0;i<10;i++)if(P[i][1]==P[i][2]&&P[i][1]==P[i][3]&&P[i][1]==P[i][4]&&P[i][1]!=-1){
            S+=P[i][1]*4;
            P[i][4]=-1; P[i][1]=-1; P[i][2]=-1; P[i][3]=-1;
        }
        for(i=0;i<10;i++)if(P[i][1]==P[i][2]&&P[i][1]==P[i][3]&&P[i][1]!=-1){
            S+=P[i][1]*3;
            P[i][1]=-1; P[i][2]=-1; P[i][3]=-1;
        }
        for(i=0;i<10;i++)if(P[i][2]==P[i][3]&&P[i][2]==P[i][4]&&P[i][2]!=-1){
            S+=P[i][2]*3;
            P[i][3]=-1; P[i][4]=-1; P[i][2]=-1;
        }
        //for(i=0;i<10;i++){for(j=0;j<5;j++)printf("%d ",P[i][j]);printf("\n");}
        a=0;
        for(;;){
            //for(i=0;i<10;i++)for(j=0;j<5;j++)if(Q[i][j]!=P[i][j])goto yare;
            if(a==1)break;
            a=1;
            yare:;
            
            for(i=0;i<9;i++)for(j=0;j<5;j++)if(P[i][j]!=-1&&P[i+1][j]==-1){
                P[i+1][j]=P[i][j];P[i][j]=-1;a=0;b=0;
            }
            
        //for(i=0;i<10;i++)for(j=0;j<5;j++)Q[i][j]=P[i][j];
        }
        
        //for(i=0;i<10;i++){for(j=0;j<5;j++)printf("%d ",P[i][j]);printf("\n");}
            
            
    }
        printf("%d\n",S);
    }
    return 0;
}
