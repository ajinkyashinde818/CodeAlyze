import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		//入力データを変数で受け取る
		int k = sc.nextInt(); //x,y,zの最大値
		int s = sc.nextInt(); //x,y,zの合計値

		//入力データを処理して、結果を出力
		int count = 0;

		for(int x = 0; x <= k; x++) {
			for(int y = 0; y <= k; y++) {
				int z = s - x - y;
				if(z >= 0 && z <= k) {
					count++;
				}
			}
		}

		System.out.println(count);

	}
}
