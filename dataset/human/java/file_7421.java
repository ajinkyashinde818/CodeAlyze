import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {

		// --- input ---
		String s = in.readLine();
		in.close();

		// --- resolv ---
		int to = s.length();
		String[] words = {"dream", "erase", "eraser", "dreamer"}; // 5,6,7
		label : while(to > 0) {
			for(String w : words) {
				if(to >= w.length() && w.equals(s.substring(to - w.length(), to))) {
					to -= w.length();
					continue label;
				}
			}
			System.out.println("NO");
			return;
		}

		System.out.println((to==0)?"YES":"NO");
	}
}
