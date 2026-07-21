import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a;
		int b;
		int[] t = new int[100011];
		for(int i=0; i<N; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			for(int j=a-1; j<=b-1; j++) {
				t[j]++;
			}
		}
		int ans = 0;
		for(int i=0; i<=100001; i++) {
			if(i<=t[i]) ans = i;
		}
		System.out.println(ans);
	}
}
