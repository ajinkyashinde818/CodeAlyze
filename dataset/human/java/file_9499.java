import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] D1 = new int[N];
		int[] D2 = new int[N];
		int a = 0;
		
		for(int i = 0; i < N; i++) {
			D1[i] = in.nextInt();
			D2[i] = in.nextInt();
		}
		
		for(int i = 0; i < N; i++) {
			if(D1[i] == D2[i]) {
				a++;
				if(a == 3) {
					System.out.println("Yes");
					break;
				}
			}else {
				a = 0;
			}
		}
		
		if(!(a == 3)) {
			System.out.println("No");
		}
	}
}
