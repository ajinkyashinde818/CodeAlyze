import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
	public static void main(String[] args) throws IOException {
		try (BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in))) {

			String in = br.readLine();
			String chr[] = in.split("");
			Arrays.sort(chr);
			String[] ans = {"a", "b", "c"};
			System.out.println(Arrays.equals(chr, ans)?"Yes":"No");

		}
	}
}
