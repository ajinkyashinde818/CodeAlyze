import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int sum = 0;
		for(int i = 0; i < 10; i++) {
			sum += stdIn.nextInt();
		}
		System.out.println(sum);
	}

}
