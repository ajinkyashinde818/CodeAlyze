import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] line = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		int[] locale = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		int[] dist = new int[line[1]];
		int ans =0;
		for (int i = 1; i < line[1]; i++) {
			dist[i - 1] = Math.abs(locale[i - 1] - locale[i]);
		}
		dist[line[1] - 1] = Math.abs(locale[line[1] - 1] - line[0]) + Math.abs(locale[0] - 0);

		Arrays.sort(dist);

		for (int i = 0; i < dist.length - 1; i++) {
			ans += dist[i];
		}

		System.out.println(ans);
	}
}
