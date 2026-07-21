import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
	 static long[] kaijo;
	 static long[] kaiinv;
//	 static int mod = 998244353;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int N = sc.nextInt();
	        String S = sc.next();
	        char[] c = S.toCharArray();
	        int[] m = new int[26];
	        for(int i=0;i<N;i++) {
	        	m[c[i]-'a']++;
	        }
	        long ans=1;
	        for(int i=0;i<26;i++) {
	        	ans=ans*(m[i]+1)%mod;
	        }
	        ans=(ans-1)%mod;
	        
	        System.out.println(ans);
	 }

}
