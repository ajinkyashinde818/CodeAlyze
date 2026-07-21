import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] a = s.toCharArray();
		char[] b = t.toCharArray();
		char temp;
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[j] < a[i]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		String s2 = "";
		for (int i = 0; i < a.length; i++) {
			s2 = s2 + a[i];
		}
		for (int i = 0; i < b.length - 1; i++) {
			for (int j = i + 1; j < b.length; j++) {
				if (b[j] > b[i]) {
					temp = b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
		}
		String t2 = "";
		for (int i = 0; i < b.length; i++) {
			t2 = t2 + b[i];
		}
		if (s2.compareTo(t2) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
