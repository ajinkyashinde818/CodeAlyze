import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			int data = scanner.nextInt();
			if (data == 0) {
				scanner.close();
				break;
			}

			char[][] symbols = new char[data][];
			symbols[0] = scanner.next().toCharArray();

			for (int i = 1; i < data; i++) {
				symbols[i] = scanner.next().toCharArray();
				for (int j = 0; j < symbols[i].length; j++) {
					if (symbols[i][j + 1] != '.') {
						// 右隣が文字の'.'は必ず'+'である
						symbols[i][j] = '+';
						for (int k = i - 1; k >= 0; k--) {
							// '+'の上にあるスペースは'|'で埋めていく
							if (symbols[k][j] == ' ') {
								symbols[k][j] = '|';
							} else {
								break;
							}
						}
						break;
					} else {
						// それ以外ならとりあえずスペースで埋めておく
						symbols[i][j] = ' ';
					}
				}
			}

			for (int i = 0; i < symbols.length; i++) {
				System.out.println(symbols[i]);
			}

		}

	}
}
