import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	// Atcoder用のサンプルプログラム
	public static void main(String[] args) {
		String line = "";
		try {
			line = readLine();

			StringTokenizer st = new StringTokenizer(line, " ");
			String tempK = st.nextToken();
			String tempS = st.nextToken();

			int k = Integer.parseInt(tempK);
			int s = Integer.parseInt(tempS);
			int cnt = 0;
			// x y S-x-y
			for (int i = 0; i < s + 1; i++) {
				if (i > k) {
					continue;
				}
				for (int j = 0; j < s + 1; j++) {
					if (j > k) {
						continue;
					} else if (s - i - j > k) {
						continue;
					}

					if (i + j <= s) {
						//System.out.println(String.valueOf(i) + "," + String.valueOf(j) + "," + String.valueOf(s - i - j));
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String readLine() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br.readLine();
	}

}
