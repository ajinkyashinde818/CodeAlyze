import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	int N, M, X;
	List<Tuple> list;
	int[] A;
	int sum = 0;

	static class Tuple {
		int C;
		int[] A;
		int maxA;

		Tuple(String line) {
			String[] tokens = line.split(" ");
			C = Integer.parseInt(tokens[0]);
			A = new int[tokens.length - 1];
			maxA = 0;
			for (int i = 1; i < tokens.length; ++i) {
				A[i - 1] = Integer.parseInt(tokens[i]);
				maxA = Math.max(maxA, A[i - 1]);
			}
		}

		double getKosupa() {
			return (double) maxA / (double) C;
		}
	}

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		X = Integer.parseInt(tokens[2]);
		list = new ArrayList<>(N);
		for (int i = 0; i < N; ++i) {
			list.add(new Tuple(in.readLine()));
		}
		Collections.sort(list, new Comparator<Tuple>() {
			@Override
			public int compare(Tuple o1, Tuple o2) {
				return -1 * Double.compare(o1.getKosupa(), o2.getKosupa());
			}
		});
		A = new int[M];
		Arrays.fill(A, 0);
	}

	int eval(Tuple tuple, int prev) {
		// まず足す必要があるか評価
		boolean result = true;
		for (int i = 0; i < M; ++i) {
			if (A[i] < X) {
				result = false;
				break;
			}
		}
		if (result) {
			return prev;
		}

		// Aに足していく．全部がX以上になればtrueを返す
		for (int i = 0; i < M; ++i) {
			A[i] += tuple.A[i];
		}
		return prev + tuple.C;
	}

	int eval(int pattern) {
		int sum = 0;
		int[] a = new int[M];
		Arrays.fill(a, 0);
		for (int i = 0; i < N; ++i) {
			if ((pattern & 1) > 0) {
				for (int j = 0; j < M; ++j) {
					a[j] += list.get(i).A[j];
				}
				sum += list.get(i).C;
			}
			pattern = pattern >> 1;
		}
		for (int i = 0; i < M; ++i) {
			if (a[i] < X) {
				return -1;
			}
		}
		return sum;

	}

	void calc() {
		sum = Integer.MAX_VALUE / 2;
		for (int i = 0; i < Math.pow(2.0, (double) N); ++i) {
			int s = eval(i);
			if (s >= 0) {
				sum = Math.min(s, sum);
			}
		}
		if (sum >= Integer.MAX_VALUE / 2 - 1) {
			sum = -1;
		}
	}

	void showResult() {
		System.out.println(sum);
	}

}
