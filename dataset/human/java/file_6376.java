import java.util.Scanner;

/**
 * B - Sum of Three Integers<br>
 * https://qiita.com/drken/items/e77685614f3c6bf86f44
 */
public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int K = in.nextInt();
		int S = in.nextInt();

		int answer = 0;

		if (S > K*3) {
			System.out.println(0);
			return;
		}

		// Z を一定の値に固定した場合で考慮
		for(int i = K; i  >= 0; i--) {
			int tmp1 = S - i;
			if (tmp1 > K + K) {
				break;
			}
			for(int j = K; j >= 0; j--) {
				int tmp2 = tmp1 - j;
				if (tmp2 < 0) {
					continue;
				}else if(tmp2 > K) {
					break;
				}
				answer++;
			}
		}

		System.out.println(answer);
	}
}
