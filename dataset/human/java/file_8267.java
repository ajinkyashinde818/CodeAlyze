import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long x=scan.nextInt();
		long y=scan.nextInt();
		scan.close();

		if(x<y) {
			long tmp=y;
			y=x;
			x=tmp;
		}

		long ans =(x*y)/gcd(x,y);
		System.out.println(ans);
	}

	static long gcd(long x,long y) {
		if(x%y==0)return y;
		else return gcd(y,x%y);
	}

}
