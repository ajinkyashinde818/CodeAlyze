import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		StringBuilder buf = new StringBuilder();
		StringBuilder buf2 = new StringBuilder();
		buf.append(str);
		int q = scan.nextInt();
		boolean invert = false;
		for (int i = 0; i<q; i++) {
			int a = scan.nextInt();
			if (a == 1) {
				invert = !invert;
			} else {
				int b = scan.nextInt();
				str = scan.next();
				char[] c = str.toCharArray();
				if (b == 1) {
					if (!invert) {
						buf2.append(c[0]);
					} else {
						buf.append(c[0]);
					}
				} else {
					if (invert) {
						buf2.append(c[0]);
					} else {
						buf.append(c[0]);
					}
				}
			}
		}
		if (invert) {
			System.out.println(new String(buf.reverse())+new String(buf2));
 		} else {
 			System.out.println(new String(buf2.reverse())+new String(buf));
 		}
	}
}
