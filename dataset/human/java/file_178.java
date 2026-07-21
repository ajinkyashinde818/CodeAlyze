import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
   public static void main(String[] args) {
	   
       Scanner sc = new Scanner(System.in);
       int N = sc.nextInt();
       long min=2200200200l;
       long ans=0;
       int cnt=0;
       int[] a = new int[(int)N];
       for (int i=0 ; i<N; i++) {
           a[i] = sc.nextInt();
           min = Math.min(min, Math.abs(a[i]));
           if(a[i]<0)cnt++;
           ans=ans+Math.abs(a[i]);
       }

       if(cnt%2==1) {
    	   ans=ans-2*min;
       }
       
       System.out.println(ans);
   }
      

}
