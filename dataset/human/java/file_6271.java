import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// 標準入力
		Scanner sc = new Scanner(System.in);

		String line1 = sc.nextLine();

		List<String> lines1 = Arrays.asList(line1.split(" "));

		Integer K = Integer.parseInt(lines1.get(0));
		Integer S = Integer.parseInt(lines1.get(1));
/*
		Integer a = S / K;
		int res = 0;

		if (3 == a) {
			res = 1;
		} else if (2 <= a) {
			res = 9;
		} else if (1 < a) {
			res = (S-K) * 3;
		}else if (1 == a) {
			res = 3;
		}
*/

		int res = 0;

		for(int x = 0; x <= K; x++) {
			for(int y = 0; y <= K; y++) {
				int z = S-x-y;
				if(0 <= z && z <= K) {
					res++;
				}
			}
		}

		System.out.println(res);
	}

}
