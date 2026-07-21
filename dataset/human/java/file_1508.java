import java.util.*;
import java.io.*;

public class Main {
	
	static int N;

	public static void main(String[] args) throws IOException {
		
		// 入出力高速化 java.io.* とthrows IOExceptionを忘れずに
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] NM = br.readLine().split(" ") ; 
		int N = Integer.parseInt(NM[0]);
		int M = Integer.parseInt(NM[1]);
		
		String[][]A = new String[N][N]; 
		String[][]B = new String[M][M]; 
		
		for(int a=0; a<N; a++) {
			A[a] = br.readLine().split("") ; 
		}
		for(int b=0; b<M; b++) {
			B[b] = br.readLine().split("") ; 
		}
		
		String ans = "No";
		//左上の点を移動させる
		for (int i=0; i<=N-M; i++) {
			for(int j=0; j<=N-M; j++) {
				boolean AequalB = true;
				for(int k=0; k<M; k++) {
					for(int l=0; l<M; l++) {
						if(!A[i+k][j+l].contentEquals(B[k][l])) {
							AequalB = false;
						}
					}
				}
				if(AequalB) {
					ans = "Yes";
				}
			}
		}
		
			
		System.out.println(ans);	
		
	}
}
