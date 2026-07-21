import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);

	void doIt() {
		sB();
	}

	void sB() {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		for(int i = 100; i >= 1; i--) {
			if(a % i == 0 && b % i == 0) {
				k--;
				if(k == 0) {
					System.out.println(i);
					return;
				
				}
			}
		}
	}
	
	public static void main(String[] args) {
		new Main().doIt();
	}
}
