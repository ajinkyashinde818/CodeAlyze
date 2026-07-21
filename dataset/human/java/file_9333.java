import java.util.Scanner;

// 提出時にclass Main に書き換え
public class Main {
	public static void main(String[] args)  {
		// 標準入力を受け取る
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // int Nを受け取る
		int zolo = 0; // ゾロ目が連続して出た回数
		boolean three = false; // ゾロ目が3回連続して出たフラグ
		for(int i = 0; i < N; i++) {
			int D1 = sc.nextInt(); // int D1を受け取る
			int D2 = sc.nextInt(); // int D2を受け取る
			if(D1 == D2) {
				zolo += 1;
			} else {
				zolo = 0;
			}
			if(zolo == 3) {
				three = true;
			}
		}
		sc.close(); // 標準入力を終了

		if (three) {
			// ゾロ目が3回以上続けて出た
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
