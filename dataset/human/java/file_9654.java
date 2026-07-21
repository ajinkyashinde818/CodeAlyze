import java.util.Scanner;

public class Main {
	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int zolome = 0;

		for (int i=0; i<n; i++){
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();

			if (d1 == d2){
				zolome++;
			} else {
				zolome = 0;
			}
			if (zolome == 3){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

}
