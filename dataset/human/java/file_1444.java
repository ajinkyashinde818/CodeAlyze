import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        String[] A = new String[N];
        String[] B = new String[M];
        for(int i=0;i<N;i++) A[i] = sc.next();
        for(int i=0;i<M;i++) B[i] = sc.next();
        for(int row=0;row<=N-M;row++){
            for(int col=0;col<=N-M;col++){
                boolean flag = true;
                for(int j=0;j<M;j++){
                    if(!B[j].equals(A[j+row].substring(col,col+M))){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    System.out.println("Yes");
                    System.exit(0);
                }
            }
        }
        System.out.println("No");
    }
}
