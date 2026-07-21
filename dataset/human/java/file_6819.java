import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int[] S ;
	public static void main(String[] args) throws Exception {
		// TODO 自動生成されたメソッド・スタブ

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String W = in.readLine();
		String[] Ws = W.split(" ");

		int K = Integer.parseInt(Ws[0]);
		int N = Integer.parseInt(Ws[1]);

		W = in.readLine();
		Ws = W.split(" ");
		long[] A = new long[Ws.length];
		long[] B = new long[Ws.length];

		for (int i = 0; i < Ws.length; i++) {
			A[i] = Long.parseLong(Ws[i]);
		}

		long max = 0;
		int maxI = 0;
		long sum = 0;
		for (int i = 0; i < Ws.length; i++) {
			if(i==0){
				B[i] = K - A[N-1] + A[0];
				max = B[i];
				maxI = i;
			}else{
				B[i] = A[i] - A[i-1];
				if(max < B[i]){
					max = B[i];
					maxI = i;
				}
			}

		}

		System.out.println(K-max);




	}

}
