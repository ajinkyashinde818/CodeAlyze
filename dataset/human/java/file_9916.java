import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		int x = Integer.parseInt(sc.next());
		
		int N = (int)Math.pow(2, n);
		
		int []c = new int [n];
		int [][]a = new int [n][m];
		
		for(int i = 0 ; i < n ;i++) {
			c[i] = Integer.parseInt(sc.next());
			for(int j = 0 ; j < m ; j++) {
				a[i][j] = Integer.parseInt(sc.next());
			}
		}
		
		long max = 100000000000000L;
		
	f:	for(int i = 0 ; i < N ;i++) {
			int []ab = new int [m];
			boolean jdg = true;
			long temp = 0;
			for(int j = 0 ; j < n ;j++) {
				if(((i >> j) & 1) == 1) {
					temp += (long)c[j];
					for(int k = 0 ; k < m ;k++) {
						ab[k] += a[j][k];
					}
				}
			}
			for(int k = 0 ; k < m ; k++) {
				if(ab[k] < x){
					jdg = false; 
				}
			}
			if(jdg) {
			max = Math.min(temp,max);
			jdg = true;
			}
		}
		
		if(max != 100000000000000L) {
			System.out.println(max);
		}
		else {
			System.out.println(-1);
		}
	}

}
