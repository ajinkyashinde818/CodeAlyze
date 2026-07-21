import java.util.*;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long A = sc.nextLong();
        long B = sc.nextLong();
        
        long ans=LCM(A,B);
        System.out.println(ans);	
        
        
    }
    
    static long GCD(long a,long b) {
  	  long tmp;
  	  long r;
  	  if(a<b) {
  		  tmp = a;
  		  a = b;
  		  b = tmp;				  
  	  }
  	  
  	  r = a % b;
  	  while(r!=0) {
  		  a=b;
  		  b=r;
  		  r=a%b;
  	  }
  	  
  	  return b;
    }
    
    static long LCM(long a,long b) {
  	  return a*b/GCD(a,b);
    }
}
