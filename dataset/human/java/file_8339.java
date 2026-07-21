import java.util.*; 

class Main{
public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
        long a=sc.nextInt();
        long b=sc.nextInt();
        long p=gcd(a,b);

    	System.out.println((a/p)*(b/p)*p);
    }


private static long gcd(long a,long b){
   if(b==0){
   	return a;
   }
	return gcd(b, a%b);
}
}
