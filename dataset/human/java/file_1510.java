import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        String[] A = new String[N];
        String[] B = new String[M];

        for(int i=0; i<N; i++){
            A[i] = sc.next();
        }
        for(int i=0; i<M; i++){
            B[i] = sc.next();
        }

        loop1:for(int i=0; i<N-M+1; i++){
            for(int j=0; j<N-M+1; j++){
                if(A[i].charAt(j)==B[0].charAt(0)){
                loop2:for(int k=0; k<M; k++){
                        for(int l=0; l<M; l++){
                            if(A[i+k].charAt(j+l)!=B[k].charAt(l)){
                                break loop2;
                            }
                        }
                        if(k==M-1){
                            System.out.println("Yes");
                            break loop1;
                        }
                    }
                }
            }
            if(i==N-M){
                System.out.println("No");
            }
        }
    }
}
