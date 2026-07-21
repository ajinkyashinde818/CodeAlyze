import java.util.*;

public class Main{
    static String[] A,B;
    static int N,M;
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        N = sc.nextInt();
        M = sc.nextInt();
        A = new String[N];
        B = new String[M];
        for(int i = 0; i < N; i++)
            A[i] = sc.next();
        for(int i = 0; i < M; i++)
            B[i] = sc.next();
        sc.close();

        for(int i = 0; i < N-M+1; i++){
            for(int j = 0; j < N-M+1; j++){
                if(include(i, j)){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }

    static boolean include(int x, int y){
       for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                if(A[i+x].charAt(j+y) != B[i].charAt(j))
                    return false;
            }
       }
       return true;
    }
}
