import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = null;
		bf = new BufferedReader(new InputStreamReader(System.in));
		int A,B,C,ans = 0;
		String str = bf.readLine();
		String[] strarr = str.split(" ");
		A = Integer.parseInt(strarr[0]);
		B = Integer.parseInt(strarr[1]);
		C = Integer.parseInt(strarr[2]);
		if(A + B + 1 >= C) {
			ans = B + C;
		} else {
			ans = A + 2*B + 1;
		}
		System.out.println(ans);
	}
}
