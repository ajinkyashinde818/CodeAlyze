import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();	//N個の街
		long k = sc.nextLong();	//k回テレポート



		int[] array = new int[n];
		for(int i = 0 ; i < n; i++) {
			array[i] = sc.nextInt();
		}

		int[] ord = new int[n+1];
		for(int i = 0; i < n + 1; i++) {
			ord[i] = -1;
		}

		int now = 1;
		List<Integer> list = new ArrayList<>();
		while(ord[now] == -1) {
			ord[now] = list.size();
			list.add(now);
			now = array[now -1];

		}

		int c = list.size() - ord[now]; //周期
		int l = ord[now];

		if(k < l) {
			System.out.println(list.get((int)k));
		}else {
			k -= l;
			k %= c;
			System.out.println(list.get((int)k+l));
		}

	}
}
