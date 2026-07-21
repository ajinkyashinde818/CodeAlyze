import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 文字列の入力
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n];
		Long[] pass = new Long[n];

		long count = 0;
		int target = 1;
		for (int i = 1; i <= n; i++) {
			a[i - 1] = sc.nextInt();
			while (target <= i) {
				count++;
				if (Objects.nonNull(pass[target - 1])) {
					//すでに通った道だとしたらループしている。
					long loopCount = count - pass[target - 1];
					long last = (k - count) % loopCount;
					target = a[Arrays.asList(pass).indexOf(pass[target - 1] + last)];
					count = k;
				} else {
					pass[target - 1] = count;
					target = a[target - 1];
				}
				if (count == k) {
					break;
				}
			}
			if (count == k) {
				break;
			}
		}

		// 出力
		System.out.println(target);
		sc.close();
	}
}
