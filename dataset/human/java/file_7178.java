import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner scan = new Scanner(System.in);

		long k, n_ken;

		k = scan.nextLong();
		n_ken = scan.nextLong();

		long[] distanceFromN = new long[(int) (n_ken) + 1];

		for (int i = 1; i <= n_ken; i++) {
			distanceFromN[i] = scan.nextLong();
		}

		long max = 0;

		//一番遠い家の距離を求める
		for (int i = 1; i <= n_ken; i++) {

			long distance = distanceFromN[i] - distanceFromN[i - 1];

			if (max < distance) {
				max = distance;
			}

			if (i == 1) {
				//初めの家は後ろ向きでも考える
				long firstDistance = distanceFromN[i] + (k - distanceFromN[(int) n_ken]);

				if (max < firstDistance) {
					max = firstDistance;
				}
			}
		}

		System.out.println(k - max);
	}

	/**
	 * 文字列を反転して返す
	 * @param pStr 文字列
	 * @return 反転した文字列
	 */
	public static String myReverse(String pStr) {
		if (pStr.length() < 1) {
			return "";
		}

		StringBuffer sb = new StringBuffer(pStr);
		return sb.reverse().toString();
	}

	/**
	 * 余りを求める。
	 * @param a
	 * @param b
	 * @return 余り。余りがマイナスの時はプラスで返す。
	 */
	public static long myMod(long a, long b) {
		long ret = 0;

		ret = a % b;

		if (ret < 0) {
			ret += b;
		}

		return ret;
	}

	/**
	 * 乗数を求める ※mod対応
	 * @param kisu 基数
	 * @param josu 乗数
	 * @param primeNumMod_0 法 mod値 使わない場合は「0」
	 * @return
	 */
	public static long myPowWithMod(long kisu, long josu, long primeNumMod_0) {

		long ans = 1;

		//乗数が0の場合→1
		if (josu == 0)
			return 1;

		if (primeNumMod_0 == 0) {
			//modを使わないとき

			while (josu > 0) {

				if (josu % 2 == 0) {
					//累乗が偶数の時

					kisu *= kisu;
					josu = josu / 2;
				} else {
					//累乗が奇数の時
					ans *= kisu;
					josu--;
				}
			}

			return ans;

		} else {
			//modを使うとき

			//初めに桁を落とす
			kisu = myMod(kisu, primeNumMod_0);

			while (josu > 0) {

				if (josu % 2 == 0) {
					//累乗が偶数の時

					kisu *= myMod(kisu, primeNumMod_0);
					josu = josu / 2;

				} else {
					//累乗が奇数の時
					ans *= myMod(kisu, primeNumMod_0);
					josu--;

				}
			}

			return myMod(ans, primeNumMod_0);

		}

	}

}
