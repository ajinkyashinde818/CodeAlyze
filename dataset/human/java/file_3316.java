import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String str = br.readLine();
			int N = Integer.parseInt(str);
			if(N % 10 == 9 || N/10 == 9) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}
//			long max  = 1000000007;
		}catch (Exception e) {
			System.exit(0);
		}
	}

}
