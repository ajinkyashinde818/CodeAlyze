import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		char[] S = sc.next().toCharArray();
		int Q = sc.nextInt();
		
		boolean rev = false;
		ArrayList<Character> head = new ArrayList<>();
		ArrayList<Character> tail = new ArrayList<>();
		
		for(int i=0; i<Q; i++) {
			int T = sc.nextInt();
			if(T==1) {
				rev ^= true;
			} else {
				int F = sc.nextInt();
				Character C = sc.next().toCharArray()[0];
				if(F==1 ^ rev) {
					head.add(C);
				} else {
					tail.add(C);
				}
			}
		}
		Collections.reverse(head);
		for(char c : S) {
			head.add(c);
		}
		for(char c : tail) {
			head.add(c);
		}
		
		if(rev)
			Collections.reverse(head);
		
		for(Character c : head) {
			pw.print(c);
		}
		pw.println();
		
		pw.close();
		sc.close();
	}
}
