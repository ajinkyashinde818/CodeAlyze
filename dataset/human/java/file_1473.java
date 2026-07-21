import java.util.*;

class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]){
        int N=sc.nextInt(),M=sc.nextInt();
        String A[]=new String[N];
        boolean F=false;
        for(int i=0;i<N;i++){
            A[i]=sc.next();
        }
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<M;i++){
            sb.append(sc.next());
        }
        String temp=sb.toString();
        for(int i=0;i<=N-M&&!F;i++){
            for(int j=0;j<=N-M&&!F;j++){
                StringBuffer sa = new StringBuffer();
                for(int k=0;k<M;k++){
                    sa.append(A[i+k].substring(j,j+M));
                }
                if(sa.toString().equals(temp)){
                    F=true;
                }
            }
        }
        System.out.println(F?"Yes":"No");
    }
}
