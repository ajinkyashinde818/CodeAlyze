import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] a = new int[M];
		for (int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		// 0の飛び石は1通り
		// 01と2つ連なっているときは1通り
		// 012と3つ連なっているとそこの進み方は2通りある
		// 0123と4つの時02,13は片方満たすと選べないので3通り
		// 01234の時02,13,24で4通り
		// 012345の時02,13,24,35と02,35で7通り
		// 0123456の時02,13,24,35,46と02,35と02,46と13,46で9通り
		// 調べた．1歩進んでN-1からNになると，
		// 2歩進んでN-2からNになるわけだからフィボナッチ数列か
		// フィボナッチ数は12くらいで桁溢れを起こすので
		// モッドにしろって言ってるわけだ
		// 石を飛ぶときはN-2から行くしかないから一通りか
		// というかそこを0にすればいいはず

		for (int i = 0; i < M - 1; i++) {
			if (a[i] + 1 == a[i + 1]) {
				System.out.println(0);
				return;
			}
		}

		long oldAns2 = 0;
		long oldAns1 = 1;
		long ans = 1;
		int mId = 0;
		for (int i = 1; i <= N; i++) {
			if (mId < M) {
				if (i == a[mId]) {
					oldAns2 = oldAns1;
					oldAns1 = 0;
					mId++;
				} else {
					ans = (oldAns1 + oldAns2) % 1000000007;
					oldAns2 = oldAns1;
					oldAns1 = ans;
				}
			} else {
				ans = (oldAns1 + oldAns2) % 1000000007;
				oldAns2 = oldAns1;
				oldAns1 = ans;
			}
		}
		System.out.println(ans);

	}
}
