import java.util.*;

class Main{
    public static void main(String[] args) {
        int C[]=new int[12];
        int temp[]=new int[12];
        int A[][]=new int [12][12];

        int N,M,X,min,tmp,flag;
        min=Integer.MAX_VALUE;

        Scanner sc=new Scanner(System.in);

        N=sc.nextInt();
        M=sc.nextInt();
        X=sc.nextInt();

        for(int i=0;i<N;i++){
            C[i]=sc.nextInt();
            for(int j=0;j<M;j++){
                A[i][j]=sc.nextInt();
            }
        }

        for(int i=0;i<Math.pow(2,N);i++){
                 tmp=0;flag=0;
            for(int m=0;m<M;m++)
                temp[m]=0;
            for(int j=0;j<N;j++){
                if((1&i>>j)==1){   
                    for(int t=0;t<M;t++)
                    temp[t]+=A[j][t];
                    tmp+=C[j];
                }
                
            }
            for(int t=0;t<M;t++)
            if(temp[t]<X){
            flag++;
            }
           // System.out.println(tmp+"  "+flag);
            if(flag==0){
            min=Math.min(min,tmp);
            }
        }
    if(min==Integer.MAX_VALUE){
    System.out.println(-1);
    System.exit(0);
    }

        System.out.println(min);
    }
}
