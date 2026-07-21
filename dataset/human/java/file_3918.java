import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int N = sc.nextInt();
			if (N == 0) break;
			char[][] th = new char[N][];
			for (int i = 0; i < N; ++i) {
				th[i] = sc.next().toCharArray();
				if (i == 0) continue;
				int head = 0;
				for (; th[i][head] == '.'; ++head) {
					th[i][head] = ' ';
				}
				--head;
				th[i][head] = '+';
				int prev = -1;
				for (int j = i - 1; j >= 0; --j) {
					if (th[j][head] == '+') {
						prev = j;
						break;
					}
					if (th[j][head] != ' ') break;
				}
				if (prev != -1) {
					for (int j = prev + 1; j < i; ++j) {
						th[j][head] = '|';
					}
				}
			}
			for (int i = 0; i < N; ++i) {
				System.out.println(String.valueOf(th[i]));
			}
		}
	}

}
