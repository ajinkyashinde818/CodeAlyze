import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		while (true) {

			int n = Integer.parseInt(br.readLine());

			if (n == 0)
				break;

			int key[] = new int[n];

			String str[] = br.readLine().split(" ");
			for (int i = 0; i < n; i++) {
				key[i] = Integer.parseInt(str[i]);
			}

			char c[] = br.readLine().toCharArray();
			int keyCount = 0;
			for (int i = 0; i < c.length; i++) {
				for (int j = 0; j < key[keyCount]; j++) {
					if (c[i] == 97)
						c[i] = 90;
					else if (c[i] == 65)
						c[i] = 122;
					else
						c[i] -= 1;
				}
				if (keyCount == key.length - 1) {
					keyCount = 0;
				} else {
					keyCount++;
				}
			}
			for (int i = 0; i < c.length; i++)
				System.out.print(c[i]);
			System.out.print("\n");
		}
	}
}
