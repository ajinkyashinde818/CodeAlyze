import java.util.*;
	import java.util.Map.Entry;
	 
	 
	 class Main {
		 static int mod =  (int) (Math.pow(10,9)+7);
//		 static int mod =  (int) 998244353;
		 public static void main(String[] args) {
	    	
	        Scanner sc = new Scanner(System.in);
	        int H = (int)Math.pow(10,6)+10;
	        int[] m = new int[H];
	        int[] p = new int[H];
	        int k=0;
	        m[1]=1;
	        for(int i=2;i<H;i++) {
	        	if(m[i]==0) {
	        		m[i]=1;
	        		p[k]=i;
	        		k++;
	        		for(int j=i+i;j<H;j=j+i) {
	        			m[j]=i;
	        		}
	        	}
	        }
	        
	        long N = sc.nextLong();
	        int[] a = new int[H];
	        for(int i=0;i<k;i++) {
	        	if(N%p[i]==0) {
	        		while(N%p[i]==0) {
	        			a[i]++;
	        			N=N/p[i];
	        		}
	        	}
	        }
	        long ans=0;
	        if(N!=1)ans++;
	        for(int i=0;i<k;i++) {
	        	int cnt=0;
	        	for(int j=1;a[i]>=j;j++) {
	        		a[i]=a[i]-j;
	        		cnt++;
	        	}
	        	ans=ans+cnt;
	        }
	        
	        System.out.println(ans);
	    }
	}
