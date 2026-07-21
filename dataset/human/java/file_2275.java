import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int N = sc.nextInt();
			int[] d = new int[100010];
			for(int i=0; i<N; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				for(int j = a; j <= b; j++) {
					d[j]++;
				}
			}
			int p;
			for(p = d.length-1; d[p] < p-1; p--) {
			}
			System.out.println(p-1);
		}
	}
}
