import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		StringBuilder sb2 = new StringBuilder();
		
		int op, rev = 0, f;
		char c;
		
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			op = sc.nextInt();
			if(op == 1)
				rev = 1-rev;
			else {
				f = sc.nextInt();
				c = sc.next().charAt(0);
				
				if(rev == 0 && f==1 || rev==1 && f==2) {
					sb2.append(c);
				}
				else {
					sb.append(c);
				}
			}
		}
		StringBuilder res = sb2.reverse().append(sb);
		
		System.out.println(rev == 0 ? res :res.reverse());
		
	}
}
