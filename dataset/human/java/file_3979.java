import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String W = in.readLine();
		int n = Integer.parseInt(W);
		int[] A = new int[n];
		int[] B = new int[n];
		int[] C = new int[n];

		W = in.readLine();
		String[] Ws = W.split(" ");
		for(int i=0;i<n;i++){
			A[i] = Integer.parseInt(Ws[i]);
		}

		W = in.readLine();
		Ws = W.split(" ");
		long point = 0;
		for(int i=0;i<n;i++){
			B[i] = Integer.parseInt(Ws[i]);
			point+=B[i];
		}

		W = in.readLine();
		Ws = W.split(" ");
		for(int i=0;i<n-1;i++){
			C[i] = Integer.parseInt(Ws[i]);
		}

		for(int i=0;i<n;i++){
			if(i != 0 && A[i-1] == A[i]-1){
				point+=C[A[i]-2];
			}
		}
		System.out.println(point);
	}
}
