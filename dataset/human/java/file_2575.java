import java.util.*;

public class Main {
	public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
		String b = sc.next();

		char[] ac = a.toCharArray();
		char[] bc = b.toCharArray();

		Arrays.sort(ac);
		Arrays.sort(bc);
		for (int i = 0; i < b.length() / 2; i++) {
			char tmp = bc[i];
			bc[i] = bc[b.length() - 1 - i];
			 bc[b.length() - 1 - i] = tmp;
		}

		String aa = new String(ac);
		String bb = new String(bc);

		int al = aa.length();
		int bl = bb.length();
		if (aa.compareTo(bb) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
