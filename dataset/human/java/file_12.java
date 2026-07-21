import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int N = sc.nextInt();
		int M = 1;
		for(; M*(M+1)<=2*N; M++) {
			if(M*(M+1)==2*N) {
				int[][] ans = new int[M+1][M];
				for(int i=0; i<M+1; i++) {
					for(int j=0; j<M; j++) {
						if(j<i) {
							ans[i][j] = ans[j][i-1];
						} else {
							ans[i][j] = (i>0 ? ans[i-1][M-1] : 0) + (j-i+1);
						}
					}
				}
				
				pw.println("Yes");
				pw.println(M+1);
				for(int i=0; i<M+1; i++) {
					pw.print(M + " ");
					for(int j=0; j<M; j++) {
						pw.print(ans[i][j] + (j==M-1 ? "\n" : " "));
					}
				}
				
				pw.close();
				sc.close();
				return;
			}
		}
		
		pw.println("No");
		
		pw.close();
		sc.close();
	}
}
