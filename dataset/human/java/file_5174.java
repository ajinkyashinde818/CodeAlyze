import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
 
public class Main {
 
	public static final MyScanner in = new MyScanner();
 
	public static void main(String[] args) {
 
		String S = in.next();
		int Q = in.nextInt();
		LinkedList<Character> pre = new LinkedList<>();
		LinkedList<Character> suf = new LinkedList<>();
		boolean reverse = false;
		for(int i=0; i<Q; i++) {
			int T = in.nextInt();
			if(T == 1) {
				reverse = !reverse;
				continue;
			}

			int F = in.nextInt();
			if (!reverse) {
				if(F == 1) {
					pre.addFirst(in.next().charAt(0));
				}else {
					suf.addLast(in.next().charAt(0));
				}
			}else {
				if(F == 1) {
					suf.addLast(in.next().charAt(0));
				}else {
					pre.addFirst(in.next().charAt(0));
				}
			}
		}

		StringBuffer answer = new StringBuffer();
		if (!reverse) {
			for(char c: pre) answer.append(c);
			answer.append(S);
			for(char c: suf) answer.append(c);
		}else {
			for(ListIterator<Character> it=suf.listIterator(suf.size()); it.hasPrevious();) answer.append(it.previous());
			char[] cs = S.toCharArray();
			for(int i=S.length()-1;i >= 0; i--) {
				answer.append(cs[i]);
			}
			for(ListIterator<Character> it=pre.listIterator(pre.size()); it.hasPrevious();) answer.append(it.previous());
		}

		System.out.println(answer.toString());
	}

	public static class MyScanner{
		Scanner sc = new Scanner(System.in);
		String nextLine() {return sc.nextLine();}
		String next() {return sc.next();}
		int nextInt() {return Integer.valueOf(sc.next());}
		long nextLong() { return Long.valueOf(sc.next());}
	}

}
