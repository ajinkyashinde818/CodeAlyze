import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int N = sc.nextInt();
			long[] A = new long[N];
			int minus = 0;
			for(int i = 0; i < N; i++) {
				A[i] = sc.nextInt();
				if(A[i] < 0) {
					minus++;
					A[i] = -A[i];
				}
			}
			long ans = 0;
			Arrays.sort(A);
			for(int i = 0; i < N; i++) {
				ans += A[i];
			}
			if(minus % 2 == 0) System.out.println(ans);
			else System.out.println(ans - 2 * A[0]);
		}
	}
}
