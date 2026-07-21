import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc=new Scanner(System.in);
    	long i=sc.nextLong(),j=sc.nextLong();
    	long m = i*j/gcd(i,j);
    	System.out.println(m);
	}
	public static long gcd(long i,long j) {
		if(j==0)
			return i;
		else
			return gcd(j,i%j);
	}
}
