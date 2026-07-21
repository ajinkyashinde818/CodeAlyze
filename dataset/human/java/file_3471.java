import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws IOException {
		try (BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in))) {

			String in = br.readLine();
			String chr[] = in.split(" ");
			char x = (chr[0].charAt(0));
			char y = (chr[1].charAt(0));
			System.out.println(x<y?"<"
							  :x>y?">"
							  :"=");

		}
	}
}
