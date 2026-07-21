import java.io.*;
import java.util.StringTokenizer;
public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		long K = Long.parseLong(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		long[] input = new long[N];
		for (int i = 0; i < N; i++) {
			input[i] = Long.parseLong(st.nextToken()) - 1;
		}
		
		long[] touch = new long[N];
		int current = 0;
		long divisor;
		while (K != 0) {
			if (touch[current] == 0) {
				touch[current] = K;
				current = (int) input[current];
				K--;
			} else {
				divisor = -K + touch[current];
				K = K % divisor;
				if (K == 0) {
					break;
				}
				current = (int) input[current];
				K--;
			}			
		}
		System.out.println(current + 1);
	}
}
