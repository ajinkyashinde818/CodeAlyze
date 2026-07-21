import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {
	int N;
	long[] A;
	long result = 0;

	Main() throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		N = Integer.parseInt(in.readLine());
		A = new long[N];
		String[] tokens = in.readLine().split(" ");
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(tokens[i]);
		}
		in.close();
		calc();
	}

	void calc() {
		int minusCount = 0;
		long minAbs = Long.MAX_VALUE;
		long absSum = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] < 0) {
				++minusCount;
			}
			long absVal = Math.abs(A[i]);
			if (minAbs > absVal) {
				minAbs = absVal;
			}
			absSum += absVal;
		}
		if (minusCount % 2 == 0) {
			this.result = absSum;
		} else {
			this.result = absSum - minAbs*2;
		}
	}

	public static void main(String[] args) throws IOException {
		Main ins = new Main();
		System.out.println(ins.result);
	}

}
