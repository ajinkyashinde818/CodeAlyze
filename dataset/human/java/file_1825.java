import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/*Atcoder用
 * 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tmp = br.readLine().split(" ");
		int a = Integer.parseInt(tmp[0]);
		int b = Integer.parseInt(tmp[1]);
		int c = Integer.parseInt(tmp[2]);


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String get = br.readLine();
		char[] s = get.toCharArray();
		for(char c:s)System.out.println(c);
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tmp = br.readLine().split(" ");
		int D = Integer.parseInt(tmp[0]);
		int G = Integer.parseInt(tmp[1]);

		ArrayList<Integer> p = new ArrayList<Integer>();
		ArrayList<Integer> c = new ArrayList<Integer>();
		int max_dec = (int) Math.pow(2, D) - 1;

		for (int d = 0; d < D; d++) {
			tmp = br.readLine().split(" ");
			int pp = Integer.parseInt(tmp[0]);
			int cc = Integer.parseInt(tmp[1]);
			p.add(pp);
			c.add(cc);
		}
		int best = 99999999;

		// TODO:D=1の処理
		// 求めて出力、exit(0);

		if(D==1){
			int point=0;
			int count=0;
			for(int i = 0;i<p.get(0)-1;i++){
				point += 100;
				count++;
				if(point>=G){
					System.out.println(count);
					System.exit(0);
				}
			}
			System.out.println(p.get(0));
			System.exit(0);
		}

		for (int i = 1; i <= max_dec; i++) {
			String bin = Integer.toBinaryString(i);

			while (bin.length() < D) {
				bin = "0" + bin;
			}
			int point = 0;
			int solvedProblem = 0;
			int maxZero = 0; // 0を持つ最大桁を探索する


			for (int j = 0; j < bin.length(); j++) {
				int b = bin.charAt(bin.length() - j - 1);
				if (b == 49) {
					boolean isFull = false;
					for (int r = 0; r < p.get(j); r++) {
						if (point >= G) {
							isFull = true;
							break;
						}
						point += (j + 1) * 100;
						solvedProblem++;
					}

					if (!isFull) {
						point += c.get(j);
					}
				} else {
					maxZero = j;
				}
			}

			if (point < G) {
				for (int j = 0; j < p.get(maxZero) - 1; j++) {
					point += (maxZero + 1) * 100;
					solvedProblem++;
					if (point >= G)
						break;
				}

				if (point < G)
					solvedProblem = 99999999;
			}

			best = Math.min(solvedProblem, best);

		}
		System.out.println(best);

	}

}
