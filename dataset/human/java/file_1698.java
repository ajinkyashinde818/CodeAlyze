import java.util.Scanner;


	public class Main {
		
		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
			
			long n = sc.nextLong();
			char[] s = sc.next().toCharArray();
			long[] alpha = new long[26];
			
			long ret = 1L;
			long x = 1000000007L;
			
			for(int i=0;i<n;i++) {
				alpha[s[i]-'a']++;
			}
			
			for(int i=0;i<26;i++) {
				if(alpha[i]==0) {
					continue;
				}else {
					ret *=alpha[i]+1;
					ret %= x;
				}
			}
			
			System.out.println(ret-1);
	    }
		
	}
