import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder(br.readLine());
		StringBuilder sb2 = new StringBuilder();
		int q = Integer.parseInt(br.readLine());
		boolean rev = false;
		for (int i = 0; i < q; i++) {
			String[] sa = br.readLine().split(" ");
			if ("1".equals(sa[0])) {
				rev = !rev;
			} else {
				if ("1".equals(sa[1]) ^ rev) {
					sb2.append(sa[2]);
				} else {
					sb.append(sa[2]);
				}
			}
		}
		br.close();

		sb2.reverse();
		sb2.append(sb);
		if (rev) {
			sb2.reverse();
		}
		System.out.println(sb2.toString());
	}
}
