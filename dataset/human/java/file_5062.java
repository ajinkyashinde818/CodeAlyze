import java.util.*;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		char c = S.charAt(0);
		Moji first = new Moji(c, null, null);
		Moji head = first;
		Moji tail = null;
		if (S.length() == 1) tail = first;
		for (int i = 1; i < S.length(); i++) {
			c = S.charAt(i);
			Moji moji = new Moji(c, first, null);
			first.back = moji;
			first = moji;
			if (i == S.length()-1) {
				tail = moji;
				//System.out.println("test");
			}
		}
		//System.out.println(tail.front);
		int Q = sc.nextInt();
		boolean front = true;

		for (int i = 0; i < Q; i++) {
			int T = sc.nextInt();
			if (T == 1) {
				if (front) front = false;
				else front = true;
			} else {
				int F = sc.nextInt();
				c = sc.next().charAt(0);
				Moji moji = new Moji(c, null, null);
				if ((F == 1 && front )||F == 2 && !front) {
					head.front = moji;
					moji.back = head;
					head = moji;
				} else {
					tail.back = moji;
					moji.front = tail;
					tail = moji;
				}
			}
		}
		if (front) {
			//System.out.println("h"+head.c);
			while (head != null) {
				System.out.print(head.c);
				head = head.back;
			}
		} else {
			//System.out.println("t"+tail.c);
			while (tail != null) {
				System.out.print(tail.c);
				tail = tail.front;
			}
		}
	}
	static class Moji {

		char c;
		Moji front;
		Moji back;

		public Moji(char c, Moji front, Moji back) {
			this.c = c;
			this.front = front;
			this.back = back;
		}
	}
}
