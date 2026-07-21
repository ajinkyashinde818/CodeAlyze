import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int Q = sc.nextInt();

		int orientation = 1;
		StringBuilder forward = new StringBuilder();
		StringBuilder backward = new StringBuilder();
		for ( int i = 0 ; i < Q ; i++ ) {
			int T = sc.nextInt();
			if ( T == 1 ) {
				orientation = -orientation;
			} else {
				int F = sc.nextInt();
				String C = sc.next();
				F = 2 * F - 3;
				if ( orientation * F > 0 ) {
					forward.append(C);
				} else {
					backward.append(C);
				}
			}
		}
		String first = null;
		String second = null;
		if ( orientation > 0 ) {
			first = backward.toString();
			second = forward.toString();
		} else {
			first = forward.toString();
			second = backward.toString();
		}

		StringBuilder rev = new StringBuilder();
		for ( int i = first.length() - 1 ; i >= 0 ; i-- ) {
			rev.append(first.charAt(i));
		}

		String SS = S;
		if ( orientation < 0 ) {
			StringBuilder revS = new StringBuilder();
			for ( int i = S.length() - 1; i >= 0 ; i-- ) {
				revS.append(S.charAt(i));
			}
			SS = revS.toString();
		}

		System.out.println(rev.toString() + SS + second);
	}
}
