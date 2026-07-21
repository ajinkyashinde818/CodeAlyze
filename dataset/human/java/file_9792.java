import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static long X;
	static long[] C;
	static long[][] A;
	public static void main(String[] args) throws IOException {
		//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//		String W	 = in.readLine();
		//		int num = Integer.parseInt(W.split(" ")[0]);

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		X = sc.nextInt();
		C = new long[N];
		A = new long[N][M];

		for(int i = 0; i<N; i++) {
			C[i] = sc.nextInt();
			for(int j = 0;j<M ; j++) {
				A[i][j] = sc.nextInt();
			}
		}

		long ans =Long.MAX_VALUE;

		boolean[] tmp = new boolean[N];

		ans = solve(tmp, 0);

		if(ans == Long.MAX_VALUE) {
			ans =-1;
		}
		System.out.println(ans);


	}

	static long solve(boolean[] tmp, int idx) {
		if(idx==N) {
			return evaluatePrice(tmp);
		}else {
			tmp[idx] = true;
			long thisTrue = solve(tmp,idx+1);
			tmp[idx] = false;
			long thisFalse = solve(tmp, idx+1);
			return Math.min(thisTrue,thisFalse );
		}
	}


	static long evaluatePrice(boolean[] tmp) {
		long[] scores = new long[M];

		for(int i=0;i<N;i++) {
			//i札目の本
			if(tmp[i]) {
				//j番目のアルゴリズムを学習
				for(int j=0; j<M;j++) {
					scores[j]+=A[i][j];
				}
			}
		}

		for(long score:scores) {
			if(score<X) {
				return Long.MAX_VALUE;
			}
		}
		//学習できた場合
		long ans = 0;
		for(int i=0;i<N;i++) {
			if(tmp[i]) {
				ans+=C[i];
			}
		}
		return ans;
	}



	//	//二分探索
	//k <= num となる最小の配列要素kのインデックスを返す
	static private int binarySearch(long num, long[] orderedArray){
		int lowerBorder = -1;
		int upperBorder = orderedArray.length;
		int mid;

		while(upperBorder - lowerBorder >1) {
			mid = (upperBorder + lowerBorder)/2;
			if(orderedArray[mid]<=num) {
				lowerBorder = mid;
			}else {
				upperBorder = mid;
			}
		}
		return lowerBorder;
	}

	//二分探索
	//k <= num となる最小のList要素kのインデックスを返す
	static private int binarySearch(long num, ArrayList<Long> orderedList){
		int lowerBorder = -1;
		int upperBorder = orderedList.size();
		int mid;

		while(upperBorder - lowerBorder >1) {
			mid = (upperBorder + lowerBorder)/2;
			if(orderedList.get(mid)<=num) {
				lowerBorder = mid;
			}else {
				upperBorder = mid;
			}
		}
		return lowerBorder;
	}

	//aとbの最小公倍数を求める
	public static int gcd(int a, int b) {
		return b == 0 ? a: gcd(b, a % b);
	}
	public static long gcd(long a, long b) {
		return b == 0 ? a: gcd(b, a % b);
	}



}
