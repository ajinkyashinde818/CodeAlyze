import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str1[] = br.readLine().split("");
		String str2[] = br.readLine().split("");

		Arrays.sort(str1, Comparator.naturalOrder());
		Arrays.sort(str2, Comparator.reverseOrder());

		int count = 0;

		for (int i = 0; i < Math.min(str1.length, str2.length); i++) {
			if (str1[i].compareTo(str2[i]) > 0) {
				System.out.println("No");
				return;
			} else if (str1[i].compareTo(str2[i]) < 0) {
				System.out.println("Yes");
				return;
			} else {
				count++;
			}
		}

		if (str1.length < str2.length) {
			if (count == str1.length || count == str2.length) {
				System.out.println("Yes");
			}
		} else {
			System.out.println("No");
		}

	}
}
