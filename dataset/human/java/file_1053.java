import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			int n = scanner.nextInt();
			if (n == 0)
				break;
			Point2D.Double[] p = new Point2D.Double[n];
			int[] r = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = new Point2D.Double(scanner.nextDouble(),
						scanner.nextDouble());
				r[i] = scanner.nextInt();
			}

			int m = scanner.nextInt();

			boolean flag;
			for (int i = 0; i < m; i++) {
				Point2D.Double t = new Point2D.Double(scanner.nextDouble(),
						scanner.nextDouble());
				Point2D.Double s = new Point2D.Double(scanner.nextDouble(),
						scanner.nextDouble());
				Line2D.Double b = new Line2D.Double(s, t);
				flag = false;
				for (int j = 0; j < n; j++) {
					double sk = s.distance(p[j]);
					double tk = t.distance(p[j]);
					if ((sk > r[j] || tk > r[j]) && b.ptSegDist(p[j]) <= r[j]) {
						flag = true;
						break;
					}
				}
				System.out.println(flag ? "Safe" : "Danger");
			}
		}
	}
}
