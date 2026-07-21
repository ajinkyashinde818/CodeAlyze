import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String str = br.readLine();
			String strr = str.substring(0,str.length()-8);
			System.out.println(strr);
//			long max  = 1000000007;
		}catch (Exception e) {
			System.exit(0);
		}
	}

}
