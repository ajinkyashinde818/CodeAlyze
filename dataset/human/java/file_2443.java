import java.awt.Point;
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		int N = Integer.parseInt(br.readLine());
		Point [] points = new Point[2*N];
		for (int j = 1;j >= -1;j -= 2) {
			int delta = (j==1)?0:N;
			for (int i = 0;i < N;i++) {
				points[delta + i] = new Point(Integer.parseInt(br.readLine()), j);
			}
		}
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				return o1.x-o2.x;
			}
		});
		long unmatched = 0, ans = 1;
		long mod = 1000000007;
		for (int i = 0; i < points.length; i++) {
			if (unmatched * points[i].y < 0) {
				ans = ans*Math.abs(unmatched);
				if (ans > mod)
					ans %= mod;
			}
			unmatched += points[i].y;
		}
		System.out.println(ans);
		br.close();
	}
}
