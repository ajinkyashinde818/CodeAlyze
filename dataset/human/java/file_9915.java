import java.util.*;
 
import java.io.*;
 
public class Main{
 
    public static long Combination(long n, long r){
        long A = 1;
        long B = 1;
        for(long i = 0; i < r; i++){
            A = A*(n-i);
            B = B*(r-i);
        }
        if(A == 0) return 0;
        return A/B;
    }
 
    public static long solve(int i, int j, boolean check, int N, String S){
        if(i == N){
            if(j == 0){
                return 1;
            }else{
                return 0;
            }
        }
 
        if(j == 0) return 1;
 
        if(check){
            return Combination(N-i, j)*(long)Math.pow(9, j);
        }else{
            if(S.charAt(i) == '0') return solve(i+1, j, false, N, S);
            long Z = solve(i+1, j, true, N, S);
            long A = solve(i+1, j-1, true, N, S)*(S.charAt(i)-'1');
            long P = solve(i+1, j-1, false, N, S);
            return Z+A+P;
        }
 
 
    }
    
    public static long Dflag(long a){
        if(a == 1) return 1;
        long h = Dflag(a/2);
        return h + h + 1;
    }
	public static void main(String[] $){
		Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int M = s.nextInt();
        int X = s.nextInt();

        int[] C = new int[N];
        int[][] A = new int[N][M];
        
        for(int i = 0; i < N; i++){
            C[i] = s.nextInt();
            for(int j = 0; j < M; j++){
                A[i][j] = s.nextInt();
            }
        }

        int min = Integer.MAX_VALUE;
        for(int i = 0; i < Math.pow(2, N); i++){
            String bin = Integer.toBinaryString(i);
            while(bin.length() != N){
                bin = "0" + bin;
            }
            boolean[] overX = new boolean[M];
            int yen = 0;
            int[] algorithm = new int[M];
            for(int j = 0; j < N; j++){
                if(bin.charAt(j) == '1'){
                    for(int k = 0; k < M; k++){
                        algorithm[k] = algorithm[k] + A[j][k];
                        if(X <= algorithm[k]) overX[k] = true;
                    }
                    yen += C[j];
                }
            }
            boolean result = false;
            for(int j = 0; j < M; j++){
                if(!overX[j]) result = true;
            }
            if(!result){
                if(min >= yen){
                    min = yen;
                }
            } 
        }
        if(min == Integer.MAX_VALUE){
            System.out.println("-1");
        }else{
            System.out.println(min);
        }
	}
}
