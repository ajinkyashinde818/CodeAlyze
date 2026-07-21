import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		if(n%2==0){
			long count=0;
			long k=5;
			while(n/(2*k)>0){
				count+=n/(2*k);
				k*=5;
			}
			System.out.println(count);
		}else{
			System.out.println(0);
		}
	}
}
