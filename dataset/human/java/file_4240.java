import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		final int NUM = scan.nextInt();
		int[] id = new int[NUM];		// 食べた料理の順番
		int[] satisfuction = new int[NUM];		// 各料理の満足度
		int[] plusSatisfuction = new int[NUM - 1];		// 連番のときに追加で得られる満足度
		int memory = Integer.MIN_VALUE;		// 直前に食べた料理の番号
		int answer = 0;			// 満足度の合計

		for(int i = 0; i < NUM; i++) {
			id[i] = scan.nextInt();
		}
		for(int i = 0; i < NUM; i++) {
			satisfuction[i] = scan.nextInt();
		}
		for(int i = 0; i < NUM - 1; i++) {
			plusSatisfuction[i] = scan.nextInt();
		}

		for(int i = 0; i < NUM; i++) {
			answer += satisfuction[id[i]-1];
			if(id[i] - 1 == memory) {
				answer += plusSatisfuction[id[i] - 2];
			}
			memory = id[i];
		}

		System.out.println(answer);

	}
}
