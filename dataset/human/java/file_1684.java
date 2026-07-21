import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long a[] = new long[26];
		String s = sc.next();
		long count =0;
		for (int i=0;i<s.length();i++) {
			long temp =1;
			for(int j=0;j<26;j++) {
				if (a[j]!=0&&j!=s.charAt(i)-'a') {
					temp =(temp *(a[j]+1))%1000000007;
				}
			}
			count =(count+temp)%1000000007;
			a[s.charAt(i)-'a']++;
		}
		System.out.println(count);
	}
}
