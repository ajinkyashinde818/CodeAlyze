import java.util.*;

public class Main{
  
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long a=sc.nextLong(),b=sc.nextLong();
    System.out.println(lcm(a,b));
  }
  static long lcm (long a, long b) {
	long temp;
	long c = a;
	c *= b;
	while((temp = a%b)!=0) {
		a = b;
		b = temp;
	  }
	return (long)(c/b);
  }
}
