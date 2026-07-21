import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner stdIn = new Scanner(System.in);
		int sum = 0;
		for(int r = 0; r < 10; r++) {
			int input = stdIn.nextInt();
			sum += input;
		}
		System.out.println(sum);
	}
}
