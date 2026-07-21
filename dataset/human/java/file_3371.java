import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		boolean isAns = false;
		if (n % 10 == 9 || n / 10 == 9)
			isAns = true;
		
		System.out.println(isAns ? "Yes" : "No");
	}
}
