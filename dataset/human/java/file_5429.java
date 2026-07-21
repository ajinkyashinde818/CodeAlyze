import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
		if (x < 1200) {
			System.out.println("ABC");
		} else {
			System.out.println("ARC");
		}

	}

}
