import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int K = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		int[] A = new int[N];
		int ans = K;
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			A[i] = Integer.parseInt(st.nextToken());
		
		ans = A[N-1] - A[0];
		
		for(int i=1; i<N; i++)
			ans = Math.min(ans, K - (A[i] - A[i-1]));
		
		System.out.println(ans);
	}

}
