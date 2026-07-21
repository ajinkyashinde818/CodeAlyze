import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int people[] = new int[100005];
		int n = Integer.parseInt(br.readLine());

		for (int i = 0; i < n; i++) {
			String str[] = br.readLine().split(" ");
			int a = Integer.parseInt(str[0]);
			int b = Integer.parseInt(str[1]);
			people[a]++;
			people[b + 1]--;
		}

		int sum = 1;
		int ans = 0;
		for (int i = 0; i < 100005; i++) {
			sum += people[i];
			if (i <= sum) {
				ans = i;
			}
		}
		System.out.println(ans - 1);
	}
}
