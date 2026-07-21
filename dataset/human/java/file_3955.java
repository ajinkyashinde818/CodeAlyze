import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] A = new String[N];
		String[] B = new String[N];
		String[] C = new String[N - 1];
		A = br.readLine().split(" ");
		B = br.readLine().split(" ");
		C = br.readLine().split(" ");

		int result = 0;
		int code = 0;
		int save = 0;

		for (int i = 0; i < N; i++) {
			code = Integer.parseInt(A[i]);
			result += Integer.parseInt(B[code - 1]);
			if (code == save) {
				result += Integer.parseInt(C[code - 2]);
			}
			save = code + 1;
		}

		System.out.println(result);

	}

}
