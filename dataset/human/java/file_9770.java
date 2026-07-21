import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int books = Integer.parseInt(sc.next());
		int algos = Integer.parseInt(sc.next());
		int level = Integer.parseInt(sc.next());

		int[][] bookArray = new int[books][algos + 1]; // [値段、1番目のスキル...]
		for (int i = 0; i < books; i++) {
			for (int j = 0; j < algos + 1; j++) {
				bookArray[i][j] = Integer.parseInt(sc.next());
			}
		}

		// 全組み合わせを検証
		int[] data = new int[books];
		for (int i = 0; i < books; i++) {
			data[i] = i;
		}
		int total = -1;
		for (int i = 1; i <= books; i++) {

			List<int[]> combination = Combination.combination(data, i);
			for (int[] combi : combination) {
				int[] sumArr = new int[algos + 1]; // 各組合せの合計の配列
				for (int index : combi) {
					for (int j = 0; j < sumArr.length; j++) {
						sumArr[j] += bookArray[index][j];
					}
//					System.out.println(Arrays.toString(sumArr));
					boolean isOKLevel = true;
					for (int j = 1; j < sumArr.length; j++) {
						if (sumArr[j] < level) {
							isOKLevel = false;
						}
					}
					if (isOKLevel && (sumArr[0] < total || total == -1)) {
						total = sumArr[0];
					}
				}
			}
		}
		System.out.println(total);

	}

}

class Combination {

	static List<String[]> combination(String[] data, int k) {
		var result = new ArrayList<String[]>();
		combination(data, 0, new String[k], 0, result);
		return result;
	}

	static void combination(String[] data, int di, String[] comb, int ci, List<String[]> result) {
		if (ci == comb.length) {
			result.add(comb.clone());
			return;
		}
		for (; di <= data.length - (comb.length - ci); di++) {
			comb[ci] = data[di];
			combination(data, di + 1, comb, ci + 1, result);
		}
	}

	static List<int[]> combination(int[] data, int k) {
		var result = new ArrayList<int[]>();
		combination(data, 0, new int[k], 0, result);
		return result;
	}

	static void combination(int[] data, int di, int[] comb, int ci, List<int[]> result) {
		if (ci == comb.length) {
			result.add(comb.clone());
			return;
		}
		for (; di <= data.length - (comb.length - ci); di++) {
			comb[ci] = data[di];
			combination(data, di + 1, comb, ci + 1, result);
		}
	}
}
