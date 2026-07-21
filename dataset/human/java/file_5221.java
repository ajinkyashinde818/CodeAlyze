import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		int q = sc.nextInt();

		LinkedList lh = new LinkedList();
		LinkedList lt = new LinkedList();
		boolean rev = false;  // reverse

		for ( int i=0; i<q; i++ ) {
			int qr = sc.nextInt();
			if ( qr == 1 ) {
				rev = !rev;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if ( (!rev && f==1) || (rev && f==2) ) {
					lh.addFirst(c);
				} else {
					lt.addLast(c);
				}
			}
		}

		StringBuffer sb = new StringBuffer(String.join("",lh)+s+String.join("",lt));
		if ( rev ) {
			System.out.println(sb.reverse());
		} else {
			System.out.println(sb);
		}
	}
}
