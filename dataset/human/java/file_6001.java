import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		if (line.equals("abc") || line.equals("acb") || line.equals("bac") || line.equals("bca") || line.equals("cab")
				|| line.equals("cba")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

}
