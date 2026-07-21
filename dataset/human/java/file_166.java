import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int[] S ;
	public static void main(String[] args) throws Exception {
		// TODO 自動生成されたメソッド・スタブ

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String W = in.readLine();
		int N = Integer.parseInt(W);


		long[] A = new long[N];
		long[] B = new long[N];

		W = in.readLine();
		String[] Ws = W.split(" ");
		long ans =0;
		long min = Long.MAX_VALUE;
		for (int i = 0; i < Ws.length; i++) {

			A[i] = Long.parseLong(Ws[i]);
			B[i] = A[i];
			if(i > 0){
				if(B[i-1] < 0 &&B[i] < 0){
					B[i-1]*=-1;
					B[i]*=-1;
				}
			}
			ans+=Math.abs(A[i]);
			min = Math.min(min, Math.abs(A[i]));
		}

		int m=0;
		for (int i = 0; i < N; i++) {
			if(B[i] < 0){
				m++;
			}
		}
		if(m%2 ==1){
			ans-=min*2;
		}

		System.out.println(ans);
	}

}
