import java.util.Scanner;

public class Main {

	Scanner sc = new Scanner(System.in);
	String station = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	void run() {
		for (;;) {
			int n = sc.nextInt();
			if (n == 0) {
				return;
			}
			int key[] = new int[n];
			for (int i = 0; i < n; i++) {
				key[i] = sc.nextInt();
			}
			String st = sc.next();
			String ans = "";
			int index = 0;
			for (int i = 0; i < st.length(); i++) {
				char obj = st.charAt(i);
				int location = 0;
				while (obj != station.charAt(location)) {
					location++;
				}
				location -= key[index++ % n];
				if (location < 0) {
					location += 52;
				}
				ans += station.charAt(location);
			}
			System.out.println(ans);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
