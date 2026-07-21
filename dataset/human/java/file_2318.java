import java.util.Scanner;

public class Main {

	private static Scanner sc=new Scanner(System.in);

	public static void main(String[] args) {
		char[] df = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
		
		
		
		
		
		while (sc.hasNextInt()) {
			int n =sc.nextInt();
			if(n==0)break;
			int[] key = new int[n];
			for (int i = 0; i < n; i++) {
				key[i] = sc.nextInt();
			}
			char[] a = sc.next().toCharArray();





			for (int i = 0; i < a.length; i++) {
				int temp;
				if ('a' <= a[i] && a[i] <= 'z') {
					temp = a[i] - 'a' + 52;
				} else {
					temp = a[i] - 'A' + 78;
				}
				temp -= (key[i % n]);
				a[i] = df[temp % 52];
			}
			
			
			
			
			
			
			String ans=new String(a);
			System.out.println(ans);
		}
	}
}
