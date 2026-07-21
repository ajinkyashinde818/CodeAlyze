import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String num = br.readLine();
		String[] str =num.split("");
		for(int i=0;i<str.length-8;i++) {
			System.out.print(str[i]);
		}
	}
}
