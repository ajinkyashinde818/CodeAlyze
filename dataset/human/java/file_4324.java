import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {


	public static void main(String[] args) throws IOException {
		BufferedReader bf = null;
		bf = new BufferedReader(new InputStreamReader(System.in));
		int ans = 0,n;
		int[] a,b,c;
		String str;
		String[] s;
		str = bf.readLine();
		n = Integer.parseInt(str);
		a = new int[n];
		b = new int[n];
		c = new int[n];
		str = bf.readLine();
		s = str.split(" ");
		for(int i = 0;i < n;++i) {
			a[i] = Integer.parseInt(s[i]);
		}
		str = bf.readLine();
		s = str.split(" ");
		for(int i = 0;i < n;++i) {
			b[i] = Integer.parseInt(s[i]);
		}
		str = bf.readLine();
		s = str.split(" ");
		for(int i = 0;i < n-1;++i) {
			c[i] = Integer.parseInt(s[i]);
		}
		for(int i = 0;i < n;++i) {
			ans += b[a[i]-1];
			if(i > 0) {
				if(a[i-1]+1 == a[i]) {
					ans += c[a[i-1]-1];
				}
			}
		}
		System.out.println(ans);
	}
}
