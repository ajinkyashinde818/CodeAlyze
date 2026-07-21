import java.util.*;
import java.lang.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		long a = sc.nextLong();
		long b = sc.nextLong();
		for( long i=1; i<=b; i++ ){
			if( (a*i)%b==0 ){
				System.out.println(a*i);
				break;
			}
		}
	}
}
