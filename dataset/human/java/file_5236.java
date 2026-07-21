import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
	 static int[] ans;
//	 static int mod = 998244353;
   public static void main(String[] args) {
	          
	   Scanner sc = new Scanner(System.in);
	   String S=sc.next();
	   int  N = sc.nextInt();
	   long[] a = new long[N];
	   long[] b = new long[N];
	   char[] c = new char[N];
	   for (int i=0 ; i<N; i++) {
		   a[i] = Long.parseLong(sc.next());
		   if(a[i]==2) {
			   b[i]=Long.parseLong(sc.next())*2-3;
			   String tmp=sc.next();
			   c[i]=tmp.charAt(0);
		   }
	   }
       
	   int tmp=1;
	   char[] sentou =new char[N];
	   char[] ato = new char[N];
	   int scnt=0;
	   int acnt=0;
	   for(int i=0;i<N;i++) {
		   if(a[i]==1) {
			   tmp=tmp*-1;
		   } else {
			   if(tmp*b[i]==-1) {
				   sentou[scnt]=c[i];
				   scnt++;
			   } else {
				   ato[acnt]=c[i];
				   acnt++;
			   }
		   }
	   }
	   
	   StringBuffer sf= new StringBuffer();
	   
	   if(tmp==-1) {
		   char[] d = S.toCharArray();
		   for(int i=acnt-1;i>=0;i--) {
			   sf.append(ato[i]);		   
		   }
		   for(int i=d.length-1;i>=0;i--) {
			   sf.append(d[i]);	
		   }
		   for(int i=0;i<scnt;i++) {
			   sf.append(sentou[i]);
		   }
	   } else {
		   for(int i=scnt-1;i>=0;i--) {
			   sf.append(sentou[i]);		   
		   }
		   sf.append(S);
		   for(int i=0;i<acnt;i++) {
			   sf.append(ato[i]);		   
		   }		   
	   }
       System.out.println(sf); 
       return;
   }

}
