import java.util.*;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		int N = Integer.parseInt(in.readLine());
		String[] tokensA = in.readLine().split(" ");
		String[] tokensB = in.readLine().split(" ");
		String[] tokensC = in.readLine().split(" ");
		int[] A = new int[N];
		int[] B = new int[N];
		int[] C = new int[N - 1];
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(tokensA[i]) - 1;
			B[i] = Integer.parseInt(tokensB[i]);
		}
		for (int i = 0; i < N - 1; ++i) {
			C[i] = Integer.parseInt(tokensC[i]);
		}

		int result = 0;
		int prev = A[0];
		result += B[prev];
		for(int i = 1; i < N; ++i) {
			int current = A[i];
			result += B[current];
			if(prev +1 == current) {
				result += C[prev];
			}
			prev = current;
		}
		System.out.println(result);

	}

}
