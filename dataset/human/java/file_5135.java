import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try(Scanner sc = new Scanner(System.in)) {
			String s = sc.next();
			ArrayDeque<String> deque = new ArrayDeque<>();
			for(int i = 0 ; i < s.length() ; i++) {
				deque.addLast(s.substring(i, i + 1));
			}
			int q = sc.nextInt();
			boolean asc = true;
			for(int i = 0 ; i < q ; i++) {
				int t = sc.nextInt();
				if(t == 1) {
					asc = !asc;
				} else {
					int f = sc.nextInt();
					String c = sc.next();
					if(f == 1) {
						if(asc) {
							deque.addFirst(c);
						} else {
							deque.addLast(c);
						}
					} else {
						if(asc) {
							deque.addLast(c);
						} else {
							deque.addFirst(c);
						}
					}
				}
			}
			int size = deque.size();
			if(asc) {
				for(int i = 0 ; i < size ; i++) {
					System.out.print(deque.pollFirst());
				}
			} else {
				for(int i = 0 ; i < size ; i++) {
					System.out.print(deque.pollLast());
				}
			}
		}

	}

}
