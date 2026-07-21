import java.util.Scanner;


public class Main {



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k=sc.nextInt();
		int s=sc.nextInt();
		for (int i=0;i<n;i++) {
			System.out.print(i<k ? s : (s+1)%1_000_000_000);
			if (i<n-1) {
				System.out.print(" ");
			}
		}
		System.out.println("");
	}

}
