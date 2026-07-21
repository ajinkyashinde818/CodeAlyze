import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] as = br.readLine().split(" ");
		int n = Integer.parseInt(as[1]);
		int r = Integer.parseInt(as[0]);
		if(r < 10) {
			System.out.println(n + 100*(10-r));
		}else {
			System.out.println(n);
		}
			
		
	}

}
