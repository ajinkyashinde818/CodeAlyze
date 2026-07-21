import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		char[] map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
				.toCharArray();
		Scanner in = new Scanner(System.in);
		int count;
		while ((count = in.nextInt()) != 0) {
			int[] key = new int[count];
			for (int i = 0; i < count; i++) {
				key[i] = in.nextInt();
			}
			char[] ango = in.next().toCharArray();
			for (int i = 0; i < ango.length; i++) {
				int posi;
				if ('a' <= ango[i] && ango[i] <= 'z') {
					posi = ango[i] - 'a' + 52;
				} else {
					posi = ango[i] - 'A' + 78;
				}
				posi -= (key[i % count]);
				ango[i] = map[posi % 52];
			}
			System.out.println(new String(ango));
		}
	}
}
