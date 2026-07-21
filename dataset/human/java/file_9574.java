//package hiougyf;
import java.io.*;
import java.util.*;
import java.util.Map.Entry;
public class Main{	
		public static void main(String[] args){  
		Scanner sc =new Scanner(System.in);
		int hh=1000000007,t=sc.nextInt();
		int ans=0,k=0;
		while(t-->0) {
		int a=sc.nextInt();
		int b=sc.nextInt();
		if(a==b) ans++;
		else if(a!=b) ans=0;
		if(ans>=3) {
			System.out.println("Yes");
			k=9;
			break;
		}
		
	}
		if(k!=9) System.out.println("No");
		
   }
		static double distance(long a,long b,long a1,long b1) {
			//System.out.println(((a-a1)*(a-a1))+((b-b1)*(b-b1)));
			double d1=Math.sqrt(((a-a1)*(a-a1))+((b-b1)*(b-b1)));
			return d1;
		}
	
	  public static int floorSqrt(int x) 
	    { 
	        // Base Cases 
	        if (x == 0 || x == 1) 
	            return x; 
	  
	        // Do Binary Search for floor(sqrt(x)) 
	        int start = 1, end = x, ans=0; 
	        while (start <= end) 
	        { 
	            int mid = (start + end) / 2; 
	  
	            // If x is a perfect square 
	            if (mid*mid == x) 
	                return mid; 
	  
	            // Since we need floor, we update answer when mid*mid is 
	            // smaller than x, and move closer to sqrt(x) 
	            if (mid*mid < x) 
	            { 
	                start = mid + 1; 
	                ans = mid; 
	            } 
	            else   // If mid*mid is greater than x 
	                end = mid-1; 
	        } 
	        return ans; 
	    } 
		static int div(int n,int b) {
			int g=-1;
			for(int i=2;i<=Math.sqrt(n);i++) {
				if(n%i==0&&i!=b) {
					g=i;
					break;
				}
			}
			return g;
		}
	 
	  
	  public static int gcd(int a, int b) 
	    { 
	        if (a == 0) 
	            return b; 
	          
	        return gcd(b%a, a); 
	    } 
	   public static int lcm(int a, int b)  
	  {  
	     return (a*b)/gcd(a, b);  
	  }  
	   public static boolean isPrime1(int n) {
           if (n <= 1) {
               return false;
           }
           if (n == 2) {
               return true;
           }
           for (int i = 2; i <= Math.sqrt(n) + 1; i++) {
               if (n % i == 0) {
                   return false;
               }
           }
           return true;
       }
       public static boolean isPrime(int n) {
           if (n <= 1) {
               return false;
           }
           if (n == 2) {
               return true;
           }
           if (n % 2 == 0) {
               return false;
           }
           for (int i = 3; i <= Math.sqrt(n) + 1; i = i + 2) {
               if (n % i == 0) {
                   return false;
               }
           }
           return true;
       }
	      
	
}
