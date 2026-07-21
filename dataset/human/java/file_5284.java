import java.util.Scanner;
public class Main {
	Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}
	
	public Main() {
		new AOJ0092().doIt();
	}
	
	class AOJ0092{
		boolean[][] t;
		int[][] w;
		void doIt(){
			while(true){
				int n = in.nextInt();
				if(n==0)return;
				t = new boolean[n][n];
				w = new int[n][n];
				int result = 0;
				for(int i=0;i<n;i++){
					char[] a = in.next().toCharArray();
					for(int s=0;s<n;s++){
						t[i][s] = a[s]=='*';
						if(t[i][s]==false)result = 1;
					}
				}
				for(int i=0;i<n;i++)for(int s=0;s<n;s++)if(!t[i][s])w[i][s] = 1;
				for(int i=1;i<n;i++)for(int s=1;s<n;s++)if(w[i][s]>0){
					int plus = Math.min(w[i][s-1], Math.min(w[i-1][s], w[i-1][s-1]));
					w[i][s] += plus;
					result = Math.max(result, w[i][s]);
				}
				System.out.println(result);
			}
		}
	}
	
}
