import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in));
		String s = br.readLine();
		int len = s.length();
		 s = s.substring(0,len-8);
		System.out.println(s);
	}
}
