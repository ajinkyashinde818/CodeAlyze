import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = 0, k = 0 ,i = 0, ans = 0;
		k = sc.nextInt();n = sc.nextInt();
      	int[] e = new int[n];
		while(i < n) {
          e[i] = sc.nextInt();
          i++;
        }
		ans = e[n - 1] - e[0];
		for (int idx = 0; idx < n -1; idx++) {
			ans = Math.min(ans, k - (e[ idx + 1] - e[idx]));
		}
		System.out.println(ans);
	}
}
