import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        char [][] A = new char [N][N];
        char [][] B = new char [M][M];
        input(A,N);
        input(B,M);
        for(int i=0; i<=N-M; i++){
            for(int j=0; j<=N-M; j++){
                if(A[i][j]==B[0][0]){
                    if(check(A,B,M,i,j)){
                        System.out.println("Yes");
                        System.exit(0);
                    }
                }
            }
        }
        System.out.println("No");
    }
    static boolean check(char[][]A, char[][]B, int M, int y, int x){
        for(int i=0; i<M; i++){
            for(int j=0; j<M; j++){
                if(A[y+i][x+j]!=B[i][j])return false;
            }
        }
        return true;
    }
    static void input(char[][]N, int X){
        for(int i=0; i<X; i++){
            String s = sc.next();
            for(int j=0; j<X; j++){
                N[i][j] = s.charAt(j);
            }
        }
    }
}
