import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		if(a/10 == 9 ||a % 10 == 9)System.out.print("Yes");
		else System.out.print("No");
	}

}
