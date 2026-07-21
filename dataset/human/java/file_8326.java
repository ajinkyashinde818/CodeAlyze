import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String W = in.readLine();

		String[] S = W.split(" ");
		int A = Integer.parseInt(S[0]);
		int B = Integer.parseInt(S[1]);

		int st =0;
		if(A < B){
			st = B;
		}else{
			st = A;
		}


		long ans = lcm(A,B);

		System.out.println(ans);



	}

private static long lcm(long m, long n) {
    return m * n / gcd(m, n);
}

private static long gcd(long m, long n) {
    if(m < n) return gcd(n, m);
    if(n == 0) return m;
    return gcd(n, m % n);
}
}
