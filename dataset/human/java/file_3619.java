import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String x = br.readLine();
		String[] num = x.split(" ");
		String y;

		int a = num[0].charAt(0);
		int b = num[1].charAt(0);

		if (a > b) {
			y = ">";
		} else if (a < b) {
			y = "<";
		} else {
			y = "=";
		}
		System.out.println(y);
	}
}
