import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		StringBuilder s = new StringBuilder(sc.next());
		StringBuilder front = new StringBuilder();
		StringBuilder rear = new StringBuilder();
		int q = sc.nextInt();
		
		int turn = 0;
		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 1) {
				turn ^= 1;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if (f == 1) {
					if (turn == 0) {
						front.append(c);
					} else {
						rear.append(c);
					}
				} else {
					if (turn == 0) {
						rear.append(c);
					} else {
						front.append(c);
					}
				}
				
			}
		}

		front = front.reverse();
		front = front.append(s.toString()).append(rear.toString());
		
		if (turn == 1) {
			front = front.reverse();
		}
		
		System.out.println(front.toString());
		
		sc.close();
	}

}
