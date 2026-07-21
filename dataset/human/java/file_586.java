import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws IOException {
		try (BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in))) {

			String in = br.readLine();
			String chr[] = in.split(" ");
			int n = Integer.parseInt(chr[0]);
			int r = Integer.parseInt(chr[1]);
			 System.out.println(n>=10 ? r : r+(100*(10-n)));
		}
	}
}
