import java.util.*;
class Main{
	public static void main(String args[]){
      Scanner sc = new Scanner(System.in);
      long r = (long)sc.nextInt();
      long c = (long)sc.nextInt();

      if(r >= 10){
				System.out.println(c);
			}
			else System.out.println(c+(100*(10-r)));


      
    }
    public static long calc(long a,long b){
      System.out.println(factorial(a)+" "+factorial(b));
      return factorial(a+b)/(factorial(a)*factorial(b));
    }

    public static long factorial(long n){
      if(n == 0){
        return new Long(1);
       }
       System.out.println(n * factorial(n-1));

      return n * factorial(n-1);
    }
}
