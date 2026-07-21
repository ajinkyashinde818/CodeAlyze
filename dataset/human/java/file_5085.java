import java.util.Scanner;



public class Main {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder s = new StringBuilder(sc.next());
		StringBuilder prefix = new StringBuilder();
		StringBuilder suffix = new StringBuilder();
		int q = sc.nextInt();
		boolean rev = false;
		for (int i=0;i<q;i++) {
			int a = sc.nextInt();
			if (a==1) {
				rev = !rev;
				StringBuilder tmp = suffix;
				suffix = prefix;
				prefix = tmp;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if (f==1) {
					prefix.append(c);
				} else {
					suffix.append(c);
				}
			}
		}
		
		prefix.reverse();
		
		if (rev) {
			s.reverse();
		}
		
		System.out.println(prefix.toString() + s + suffix);



	
	}
	


}
