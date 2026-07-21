import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	
		ArrayDeque<String> deque = new ArrayDeque<String>();
		StringBuilder sb = new StringBuilder();
		String s = sc.next();
		
		int q = Integer.parseInt(sc.next());
		int top = 1;
		deque.add(s);
		
		for(int i = 0 ;i < q ;i++) {
			int p = Integer.parseInt(sc.next());
			if(p == 1) {
				top *= -1;
			}
			else {
				int r = Integer.parseInt(sc.next());
				String c = sc.next();
				if(r == 1) {
					if(top > 0) {
						deque.addFirst(c);
					}
					else {
						deque.addLast(c);
					}
				}
				else {
					if(top > 0) {
						deque.addLast(c);
					}
					else {
						deque.addFirst(c);
					}
				}
			}
		}
	
		int m = deque.size();
			for(int i = 0 ;i < m ; i++) {
				sb.append(deque.pollFirst());
			}
		if(top < 0) { 
			sb.reverse();
			}
		
		System.out.println(sb.toString());
		
		
		
	}
}
