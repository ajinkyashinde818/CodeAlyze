import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int a[] = new int[3];
		for (int i=0;i<3;i++) {
			a[s.charAt(i)-'a']++;
		}
		for(int i=0;i<3;i++) {
			if (a[i]!=1) {
				System.out.println("No");
				return ;
			}
		}
		System.out.println("Yes");
	}
}
