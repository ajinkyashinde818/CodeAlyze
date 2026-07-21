import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int[] a = new int[26];
		for (int i=0;i<n;i++) {
			a[s.charAt(i)-'a']++;
		}
		long ans = 1;
		for (int i=0;i<26;i++) {
			ans=ans*(a[i]+1)%1_000_000_007;
		}
		System.out.println(ans-1);

	}
}
