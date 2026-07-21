import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		sc.close();
		if(n%2==1) System.out.println(0);
		else {
			long count=0,div=10;
			while(div<=n) {
				count += n/div;
				div *= 5;
			}
			System.out.println(count);
		}
	}
}
