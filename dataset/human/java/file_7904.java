import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[] imput = new int[10];
		int sum =0;
		Scanner stdin = new Scanner(System.in);

		for(int i = 0; i < 10; i++) {
			imput[i]  = stdin.nextInt();
			sum += imput[i];
		}
		System.out.println(sum);

	}

}
