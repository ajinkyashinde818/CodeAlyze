import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		if(s<1000000000) {
			for(int i=0; i<k; i++) {
				System.out.print(s +" ");
			}
			
			for(int i=0; i<n-k; i++) {
				System.out.print((s+1) + " ");
			}
		}else {
			for(int i=0; i<k; i++) {
				System.out.print(s +" ");
			}
			
			for(int i=0; i<n-k; i++) {
				System.out.print(1 + " ");
			}
		}
	}

}
