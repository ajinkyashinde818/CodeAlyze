import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	//java11

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		long K =sc.nextLong();

		//テレポート先
		int[] A = new int[N+1];

		for(int i=1; i<=N; i++) {
			A[i] = sc.nextInt();
		}

		int ans = 1;
		long index = 1;

		//loop考慮なし
		if(K <=N) {

			while(index <= K) {
				ans = A[ans];
				index++;
			}

		}
		else {
			//loopを検出
			boolean[] checked = new boolean[N+1];
			Arrays.fill(checked, false);
			List<Integer> loop = new ArrayList<>();
			int before_loop_n = 0;

			while(index <= K) {
				loop.add(ans);
				checked[ans] = true;

				//loopの終わり
				if(checked[A[ans]]) {
					//先頭からA[ans]の前までを削除
					int a = 1;
					while(a != A[ans]) {
						loop.remove(0);
						before_loop_n++;
						a = A[a];
					}
					break;
				}

				ans = A[ans];
				index++;
			}

			ans = 1;
			index = 1;
			if(K <= before_loop_n-1) {
				while(index <= K) {
					ans = A[ans];
					index++;
				}
			}
			else {
				int loop_index = (int)((K - before_loop_n) % loop.size());
				ans = loop.get(loop_index);
			}
		}

		System.out.println(ans);
	}

}
