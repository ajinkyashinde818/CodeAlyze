import java.util.ArrayList;
import java.util.Scanner;

class Main{

	static int N;
	static int M;
	static 		ArrayList<ArrayList<Integer>> map;



	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);			//文字の入力
		N = sc.nextInt();
		long[] a = new long[N];
		long sum = 0;
		
		a[0] = sc.nextLong();
		for(int i = 1;i < N;i++){
			a[i] = sc.nextLong()+a[i-1];
		}
		sum = a[N-1];
		
		long ans = 1000000000000000L;
		for(int i = 0;i < N-1;i++){
			long score = Math.abs(a[i] - (sum - a[i]));
			ans = Math.min(ans, score);
		}
		System.out.println(ans);
		
		
	}

}
