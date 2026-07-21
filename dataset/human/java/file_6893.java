import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
//	 static int mod = 998244353;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        long K = sc.nextLong();
	        int N = sc.nextInt();
	        long[] a = new long[N];
	        for (int i=0 ; i<N; i++) {
	            a[i] = Long.parseLong(sc.next());
	        }
	        
	        long max=a[0]+(K-a[N-1]);
	        for(int i=0;i<N-1;i++) {
	        	max=Math.max(max, a[i+1]-a[i]);
	        }
	        long ans= K-max;
        	System.out.println(ans);
	        	        
	 }
}
