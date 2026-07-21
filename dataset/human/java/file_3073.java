import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int go[] = new int[N];
		int arrive[] = new int[N];
		for (int i=0;i<M;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (a==1) {
				go[b-1]=1;
			} else if (b==N) {
				arrive[a-1]=1;
			}
		}
		for (int i=0;i<N;i++) {
			if (go[i]==1&&arrive[i]==1) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
