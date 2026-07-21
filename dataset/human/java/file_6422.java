import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException  {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" ");
		int max = Integer.parseInt(s[0]);
		int ans = Integer.parseInt(s[1]);
		
		int result = 0;
		for(int i=0; i<=max; i++) {
			for(int j=0; j<=max; j++) {
				int k = ans - (i + j);
				if(0 <= k && k <= max) result++;
			}
		}
		System.out.println(result);
	}

}
