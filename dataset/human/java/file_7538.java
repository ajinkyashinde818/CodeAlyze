import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] ary = new char[s.length()];
		for (int i = 0; i < s.length(); i++) {
			ary[i] = s.charAt(i);
		}

		int index = s.length();
		char[] dreamer = { 'r', 'e', 'm', 'a', 'e', 'r', 'd' };
		char[] dream = { 'm', 'a', 'e', 'r', 'd', '&', '&' };
		char[] eraser = { 'r', 'e', 's', 'a', 'r', 'e', '&' };
		char[] erase = { 'e', 's', 'a', 'r', 'e', '&', '&' };

		int iDreamer = 0;
		int iDream = 0;
		int iEraser = 0;
		int iErase = 0;

		while (true) {
			if (index == 0) {
				System.out.println("YES");
				break;
			} else if (index < 5) {
				System.out.println("NO");
				break;
			}
			iDreamer = 0;
			iDream = 0;
			iEraser = 0;
			iErase = 0;
			int dex = 0;
			for (int i = index - 1; i >= index - 7 && i >= 0; i--) {
				if (dreamer[dex] == ary[i]) {
					iDreamer++;
				}
				if (dream[dex] == ary[i]) {
					iDream++;
				}
				if (eraser[dex] == ary[i]) {
					iEraser++;
				}
				if (erase[dex] == ary[i]) {
					iErase++;
				}
				dex++;
			}
			if (iDreamer != 7) {
				iDreamer = 0;
			}
			if (iDream != 5) {
				iDream = 0;
			}
			if (iEraser != 6) {
				iEraser = 0;
			}
			if (iErase != 5) {
				iErase = 0;
			}
			int m = Math.max(Math.max(iErase, iEraser), Math.max(iDreamer, iDream));
			if (m == 0) {
				System.out.println("NO");
				break;
			}
			index -= m;

		}
		return;
	}
}
