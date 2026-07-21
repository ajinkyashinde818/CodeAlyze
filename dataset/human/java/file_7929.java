import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int sum = 0;
		for(int i=1; i<=10; i++){
			sum += scan.nextInt();
		}
		System.out.println(sum);
	}
}
