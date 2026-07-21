import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		int s = scan.nextInt();


		if(s <= 2) {
			for(int i = 0; i < n; i++) {
				if(i < k) {
					System.out.print(s + " ");
				}else {
					System.out.print((s+1) + " ");
				}
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(i < k) {
					System.out.print(s + " ");
				}else {
					System.out.print((s-1) + " ");
				}
			}
		}
	}

}
