import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		long[] c = new long[26];
		int n = sc.nextInt();
		String s = sc.next();
		for(int i = 0; i < n; i++){
			c[s.charAt(i)-97]++;
		}
		long ans = 1;
		for(int i = 0; i < 26; i++){
			ans=ans*(c[i]+1)%1000000007;
		}
		System.out.print(ans-1);
	}
}
