import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int n = sc.nextInt();
		// スペース区切りの整数の入力
		int y = sc.nextInt();

		int[] a = new int[n];
		for( int i=0 ; i<y ; i++ ) {
			a[i] = sc.nextInt();
		}
		Calc res = new Calc(n,y, a);
		System.out.println( res.toString() );
	}
	public static class Calc {
		int K;
		int N;
		
		int[] A;
		
		int start;
		int end;
		
		int dist;
		public Calc(int k, int n, int[] a) {
			K = k;
			N = n;
			A = a;
			
			int dist = K - a[n-1] + a[0];
			start = 0;
			for( int i=0 ; i<n-1 ; i++ ) {
				if( dist < a[i+1] - a[i] ) {
					start = i+1;
					dist = a[i+1] - a[i];
				}
			}
//			
//			dist = (K + a[start -1] - a[start]) % K;
			
			this.dist = K - dist;
		}



		@Override
		public String toString() {
			return ""+ dist;
		}
		
		

	}
	
}
