import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line[] = br.readLine().split(" ");
		int k = Integer.parseInt(line[0]);
		int s = Integer.parseInt(line[1]);
		int count = 0;

		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (0 <= s - i - j && s - i - j <= k) {
					count++;
				}
			}
		}

		System.out.println(count);
	}

}
