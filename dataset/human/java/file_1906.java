import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int d = scan.nextInt();
		long g = scan.nextLong();
		long min = 1<<29;
		int[] p = new int[d];
		int[] c = new int[d];
		for (int i = 0; i < d; i++) {
			p[i] = scan.nextInt();
			c[i] = scan.nextInt();
		}
		for (int bit = 0; bit < (1 << d) ; bit++) {
			long sum = 0;
			int count = 0;
			for (int i = 0; i < d; i++) {
				if ((bit & (1<< i)) != 0) {
					sum += c[i ]+ (p[i]*100*(i+1));
					count += p[i];
				}
			}
				if (sum>=g) min = Math.min(min, count);
				else {
					for (int j = d-1; j >= 0; j--) {
						if ((bit & (1<< j)) != 0) continue;
						for (int k = 0; k < p[j]; k++) {
							if (sum>=g) break;
							sum += (j+1)*100;
							count++;
						}
					}
					min = Math.min(min, count);
				}
			}
		System.out.println(min);
	}
}
