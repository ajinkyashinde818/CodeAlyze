import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = null;
		bf = new BufferedReader(new InputStreamReader(System.in));
		int a,b,k,ans = 0,temp;
		String str = bf.readLine();
		String[] arrs = str.split(" ");
		a = Integer.parseInt(arrs[0]);
		b = Integer.parseInt(arrs[1]);
		k = Integer.parseInt(arrs[2]);
		for(int i = 100;i>0;--i) {
			if(a%i==0 && b%i==0) {
				k--;
				if(k == 0) {
					ans = i;
					break;
				}
			}
		}
		System.out.println(ans);
	}
}
