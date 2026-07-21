import java.util.*;
import java.util.stream.Collectors;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	Deque<Character> deque = new ArrayDeque<>();
	boolean isInv = false;
	List<Query> queries = new ArrayList<>();

	static class Query {
		int T, F;
		Character C;

		Query(String line) {
			String[] tokens = line.split(" ");
			T = Integer.parseInt(tokens[0]);
			if (T == 2) {
				F = Integer.parseInt(tokens[1]);
				C = tokens[2].charAt(0);
			}
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
		String S = in.readLine();
		for (int i = 0; i < S.length(); ++i) {
			deque.add(S.charAt(i));
		}
		int Q = Integer.parseInt(in.readLine());
		for (int i = 0; i < Q; ++i) {
			queries.add(new Query(in.readLine()));
		}
	}

	void calc() {
		for (int i = 0; i < queries.size(); ++i) {
			Query query = queries.get(i);
			if (query.T == 1) {
				isInv = !isInv;
			} else {
				if (!isInv) {
					// そのままの評価
					if (query.F == 1) {
						deque.addFirst(query.C);
					} else {
						deque.addLast(query.C);
					}
				} else {
					// 逆の評価
					if (query.F == 1) {
						deque.addLast(query.C);
					} else {
						deque.addFirst(query.C);
					}
				}
			}
		}
	}

	void showResult() {
		StringBuilder strBuilder = new StringBuilder();
		while (!deque.isEmpty()) {
			if (!isInv) {
				strBuilder.append(deque.pollFirst());
			} else {
				strBuilder.append(deque.pollLast());
			}
		}
		System.out.println(strBuilder.toString());
	}

}
