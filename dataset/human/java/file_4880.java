import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long count = 0;
		if(n%2 == 0) {
			long five = 5;
			while(five <= n) {
				count += (n/five)/2;
				five = five * 5;
			}
		}else if(n%2 == 1){
			count = 0;
		}
		System.out.println(count);
		sc.close();
	}
}
