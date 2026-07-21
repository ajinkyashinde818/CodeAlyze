import java.util.*;
import java.util.stream.Collectors;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	static class Tuple {
		int p;
		int c;
		int baseScore;

		Tuple(int p, int c, int baseScore) {
			this.p = p;
			this.c = c;
			this.baseScore = baseScore;
		}
	}

	Tuple[] problems;
	int D, G;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		D = Integer.parseInt(tokens[0]);
		G = Integer.parseInt(tokens[1]);
		this.problems = new Tuple[D];
		for (int i = 0; i < D; ++i) {
			tokens = in.readLine().split(" ");
			int p = Integer.parseInt(tokens[0]);
			int c = Integer.parseInt(tokens[1]);
			problems[i] = new Tuple(p, c, (i + 1) * 100);
		}
	}

	int getSolveProblems(int pattern) {
		// まず解く問題セットを求める
		List<Tuple> list = new ArrayList<>();
		for (int i = 0; i < D; ++i) {
			if ((pattern & 1) > 0) {
				list.add(problems[i]);
			}
			pattern >>= 1;
		}
		// まずscoreと解く問題数を求める
		int solveNum = 0;
		int score = 0;
		for (Tuple tuple : list) {
			solveNum += tuple.p;
			score += tuple.p * tuple.baseScore + tuple.c;
		}
		// 足りない場合は-1を返す
		if (score < G) {
			return -1;
		}
		// 足りている場合，ギリギリまで解く問題数を削減する
		Collections.sort(list, new Comparator<Tuple>() {
			@Override
			public int compare(Tuple o1, Tuple o2) {
				return Integer.compare(o1.baseScore, o2.baseScore);
			}
		});
		Tuple t = list.get(0);
		score -= t.c;
		if (score < G) {
			// 全問解かないといけない
			return solveNum;
		}
		for (int i = 0; i < t.p; ++i) {
			score -= t.baseScore;
			solveNum--;
			if (score < G) {
				break;
			}
		}
		score += t.baseScore;
		if (score >= G) {
			return solveNum + 1;
		} else {
			return -1;
		}

	}

	void calc() {
		int solveNum = Integer.MAX_VALUE;
		for (int i = 1; i < Math.pow(2, D); ++i) {
			int num = getSolveProblems(i);
			if (num >= 0) {
				solveNum = Math.min(solveNum, num);
			}
		}
		System.out.println(solveNum);
	}

	void showResult() {
	}
}
