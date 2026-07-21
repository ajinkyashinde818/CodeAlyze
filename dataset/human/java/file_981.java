/*package whatever //do not write package name here */

import java.util.*;

public class Main {
	public static void main (String[] args) {
	    
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        long c = sc.nextLong();
        long x[] = new long[n];
        long v[] = new long[n];
        long l[] = new long[n];
        long r[] = new long[n];
        for(int i=0;i<n;i++){
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }
        long ans = 0l;
        for(int i=0;i<n;i++){
            if(i==0) {
                l[i] = v[i];
                continue;
            }
            l[i] = l[i-1]+v[i];
        }
        
        for(int i=0;i<n;i++){
            l[i]-=x[i];
            ans = Math.max(ans, l[i]);
        }
        
        
        //also do this for going right
        r[0] = v[n-1];
        for(int i=1;i<n;i++){
            r[i] = r[i-1]+v[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            r[i] -= c-x[n-i-1];
            ans = Math.max(ans, r[i]);
        }
        
        long ll[]  =new long[n];
        long rr[]  =new long[n];
        
        for(int i=0;i<n;i++){
            ll[i] = l[i]; 
            rr[i]=r[i];
        }
        for(int i=1;i<n;i++){
            rr[i] = Math.max(rr[i], rr[i-1]);
            ll[i] = Math.max(ll[i], ll[i-1]);
        }
        
        //System.out.println(Arrays.toString(ll)+" " + Arrays.toString(rr));
        //System.out.println(Arrays.toString(l)+" " + Arrays.toString(r));
        
        //go to left and then come back to right. for all these cases
        for(int i=0;i<n-1;i++){
            //System.out.print(r[i] - c- x[n-1-i]+" ");
            ans = Math.max(ans, l[i] - x[i] + rr[n-i-2]);
            ans = Math.max(ans, r[i] - (c- x[n-1-i]) + ll[n-i-2]);
        }
        System.out.println(ans);
    }
}
