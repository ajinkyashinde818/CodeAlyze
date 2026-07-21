import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		String m = "";
        String ans = "NO";
		try {
			m = sc.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (m.matches("^(dream|dreamer|erase|eraser)+$")) {
  		    ans = "YES";
        }

		System.out.println(ans);
	}
}
