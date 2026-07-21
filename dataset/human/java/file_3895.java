import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
//	 static int mod = 998244353;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        String S = sc.next();
	        char[]c = S.toCharArray();
	        int N = c.length;
	        
	        char[] ab = new char[N];
	        int[] x = new int[N+5];
	        int cntx=0;
	        int cntab=0;
	        for(int i=0;i<N;i++) {
	        	if(c[i]=='x') {
	        		x[cntx]++;
	        	} else {
	        		ab[cntab]=c[i];
	        		cntab++;
	        		cntx++;
	        	}
	        }
	        
	        for(int i=0;i<cntab/2;i++) {
	        	if(ab[i]!=ab[cntab-1-i]) {
	        		System.out.println(-1);
	        		return;
	        	}
	        }
	   	 	int ans=0;
	        for(int i=0;i<(cntx+1)/2;i++) {
	        	ans=ans+Math.abs(x[i]-x[cntx-i]);
	        }
	   	 	
	   	 System.out.println(ans);
	 }
	 

}
