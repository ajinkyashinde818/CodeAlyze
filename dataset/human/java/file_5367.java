import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        // Here your code !
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();

        int num = Integer.parseInt(line);
        
		if (num < 1200) {
			System.out.println("ABC");
		} else {
			System.out.println("ARC");
		}
	}
}
