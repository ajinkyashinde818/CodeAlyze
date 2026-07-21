import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Twin_string ts = new Twin_string(sc.next());
		int q = sc.nextInt(); int f;
		boolean rev = false;
		for (int i = 0; i < q; i++) {
			if(sc.nextInt()==1) rev = !rev;
			else {
				f = sc.nextInt();
				String c = sc.next();
				if((!rev&&f==1)||(rev&&f==2)) ts.addFirst(c);
				else ts.addLast(c);;
			}
		}
		System.out.println(ts.toString(rev));
	}
	public static class Twin_string{
		StringBuilder sb1, sb2;
		public Twin_string(String s) {
			sb1 = new StringBuilder();
			sb2 = new StringBuilder(s);
		}
		public void addFirst(String s) {
			sb1.append(s);
		}
		public void addLast(String s) {
			sb2.append(s);
		}
		public String toString(boolean rev) {
			if(rev) return new String(sb2.reverse()) + new String(sb1);
			else return new String(sb1.reverse()) + new String(sb2);
		}
	}
}
