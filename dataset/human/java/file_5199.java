import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int Q = sc.nextInt();

		StringBuffer sbNormal = new StringBuffer(S);
		StringBuffer sbReverse = new StringBuffer();
		boolean reverse = false;

		for (int i=0; i<Q; i++){
			int T = sc.nextInt();
			if (T == 1){
				reverse = !reverse;
			} else {
				int F = sc.nextInt();
				char C = sc.next().charAt(0);
				if ((F == 1 && !reverse) || (F == 2 && reverse)) {
					sbReverse.append(C);
				} else {
					sbNormal.append(C);
				}
			}
		}
		if (reverse) {
			System.out.println(sbNormal.reverse().append(sbReverse).toString()
					);
		} else {
			System.out.println(sbReverse.reverse().append(sbNormal).toString());
		}

	}
}
