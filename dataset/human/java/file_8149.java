import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long a=sc.nextInt();
		long b=sc.nextInt();
		long c=a*b;
		long x=Math.max(a, b);
		long y=Math.min(a, b);
		while(y!=0) {
			long h=y;
			y=x%y;
			x=h;
		}
		System.out.println(c/x);

	}

}
