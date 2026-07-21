import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long A[] = new long[N];
        for(int i=0;i<N;i++){
            A[i] = sc.nextInt();
        }
        sc.close();
        if (posneg(A) % 2 == 0){
            for(int l=0;l<N;l++){
                A[l] = Math.abs(A[l]);
            }
            System.out.println(Arrays.stream(A).sum());
        }
        else{
            long pin = 1000000000;
            for(int j=0;j<N;j++){
                if (Math.abs(A[j]) <= pin){
                    pin = (long)Math.abs(A[j]);
                }
            }
            for(int k=0;k<N;k++){
                A[k] = Math.abs(A[k]);
            }
            System.out.println((long)Arrays.stream(A).sum()-2*pin);
        }
    }
    public static int posneg(long P[]){
        int negcnt = 0;
        for(int i=0;i<P.length;i++){
            if (P[i] < 0){
                negcnt += 1;
            }
        }
        return negcnt;
    }
}
