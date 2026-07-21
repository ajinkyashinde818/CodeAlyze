import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();


		if(a>=b) {
			System.out.println(a*b/res(a,b));
		}else {
			System.out.println(a*b/res(b,a));
		}


	}
	public static Long res(long a,long b) {
		long res;
		res = a%b;
		if(res==0) {
			return b;
		}
		return res(b,res);
	}
}
