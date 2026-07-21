import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		char[] data1 = s1.toCharArray();
		String s2 = sc.next();
		char[] data2 = s2.toCharArray();
		for (int k = 0; k < data1.length - 1; k++) {
			for (int i = 0; i < data1.length - 1; i++) {
				if (data1[i] > data1[i + 1]) {
					char a = data1[i];
					data1[i] = data1[i + 1];
					data1[i + 1] = a;
				}
			}
		}
		for (int k = 0; k < data2.length - 1; k++) {
			for (int i = 0; i < data2.length - 1; i++) {
				if (data2[i] < data2[i + 1]) {
					char a = data2[i];
					data2[i] = data2[i + 1];
					data2[i + 1] = a;
				}
			}
		}

		String st1 = String.valueOf(data1);
		String st2 = String.valueOf(data2);
		int j = st1.compareTo(st2);
		if (j < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		sc.close();
	}

}
