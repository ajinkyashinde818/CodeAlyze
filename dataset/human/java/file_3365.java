import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N = br.readLine();
		
		if (N.contains("9")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	
	}
 
}
