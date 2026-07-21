import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int Q = sc.nextInt();
		boolean isreverse = false;
		StringBuilder ans = new StringBuilder(S);
		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();
		for(int i = 0; i < Q; i++) {
			if(sc.nextInt() == 1) {
				if(isreverse)
					isreverse = false;
				else
					isreverse = true;
			}
			else {
				int F = sc.nextInt();
				String C = sc.next();
				if(F == 1) {
					if(isreverse)
						tail.append(C);
					else
						head.append(C);
				}
				else {
					if(isreverse)
						head.append(C);
					else
						tail.append(C);
				}
			}
		}
		ans.insert(0, head.reverse());
		ans.append(tail);
		System.out.println(isreverse ? ans.reverse() : ans);

	}

}
