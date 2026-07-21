import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		StringBuilder sb1 = new StringBuilder("");
		StringBuilder sb2 = new StringBuilder("");
		int Q = Integer.parseInt(sc.next());
		boolean order = true;
		for(int i = 0; i < Q; i++) {
			int T = Integer.parseInt(sc.next());
			if(T == 1) {
				order = !order;
			} else {
				int f = Integer.parseInt(sc.next());
				if(f == 1) {
					boolean temp_order = !order;
					if(temp_order) {
						sb2.append(sc.next());
					} else {
						sb1.append(sc.next());
					}
				} else {
					if(order) {
						sb2.append(sc.next());
					} else {
						sb1.append(sc.next());
					}
				}
			}
		}
		StringBuilder ans = new StringBuilder(sb1.reverse().append(sb.append(sb2)));
		if(order) {
			System.out.println(ans);
		} else {
			System.out.println(ans.reverse());
		}
	}
}
