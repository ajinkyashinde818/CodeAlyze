import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		int canEat = c > a + b ? a + b * 2 + 1 : b + c;
		System.out.println(canEat);

		sc.close();
	}

}
