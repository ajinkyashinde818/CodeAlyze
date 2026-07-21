import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int isshuu = sc.nextInt();
			int ienokazu = sc.nextInt();
			int[] ienozahyo = new int[ienokazu];
			for (int i = 0; i < ienokazu; i++) {
				ienozahyo[i] = sc.nextInt();
			}

			int[] ienoaida = new int[ienokazu];
			for (int i = 0; i < ienokazu - 1; i++) {
				ienoaida[i] = ienozahyo[i + 1] - ienozahyo[i];
			}
			ienoaida[ienokazu - 1] = isshuu - ienozahyo[ienokazu - 1] + ienozahyo[0];

			//一番間隔が広い家の間の距離を探す
			int maxtooi = 0;
			for (int i = 0; i < ienokazu - 1; i++) {
				if (ienoaida[i] > ienoaida[i + 1]) {
					if (maxtooi < ienoaida[i]) {
						maxtooi = ienoaida[i];
					}
				}
			}
			if (maxtooi < ienoaida[ienokazu - 1]) {
				maxtooi = ienoaida[ienokazu - 1];
			}

			System.out.println(isshuu - maxtooi);
		} finally {
			sc.close();
		}
	}

}
