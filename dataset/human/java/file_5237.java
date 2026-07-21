import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int q = in.nextInt();
		StringBuilder str1 = new StringBuilder();
		StringBuilder str2 = new StringBuilder(s);
		boolean hanten =false;
		for (int i = 0; i < q; i++) {
			int t = in.nextInt();
			if (t == 1) {
				hanten = !hanten;
			} else {
				int f = in.nextInt();
				String c = in.next();
				if(hanten == false){
					if (f == 1) {
						str1.append(c);
					} else {
						str2.append(c);
					}
				} else {
					if (f == 1) {
						str2.append(c);
					} else {
						str1.append(c);
					}
				}
			}
		}
		if(hanten){
			str2.reverse().append(str1);
			System.out.println(str2);
		} else {
			str1.reverse().append(str2);	
			System.out.println(str1);
		}
	}
}
