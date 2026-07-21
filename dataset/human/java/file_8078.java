import java.util.Scanner;
import java.util.Arrays;
public class Main
{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt(); int x = a;
		int b = scan.nextInt(); int y = b;
		long lcm = (long)a*b;
		for(int i =0; i<1000000; i++){
		    if(a ==0 || b==0){
		        break;
		    }
		    else{
		        if(a<b){
		            int g = a;
		            a = b%a;
		            b = g;
		        }
		        else{
		            int g = b;
		            b = a%b;
		            a =g;
		        }
		    }
		}
		int gcd = Math.max(a, b);
		lcm = lcm/gcd;
		System.out.println(lcm);
	}
}
