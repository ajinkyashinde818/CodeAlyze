import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		if(num%2==1){
			System.out.println(0);
		}
		else {

			long sum=0;
			for (long i = 5; i<=2*num; i=5*i) {
				sum += (long)(num/(2*i));
			}
			System.out.println(sum);
		}
	}
}
