import java.util.*;
public class Main {

		static void solve() {
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			int sum = 0;
			int[] dishes = new int[n];
			int[] bpoints = new int[n];
			int[] cpoints = new int [n-1];
			for(int i = 0;i<n;i++) {
				dishes[i] = sc.nextInt();
			}
			for(int i = 0;i<n;i++) {
				bpoints[i] = sc.nextInt();
			}
			for(int i = 0;i<n-1;i++) {
				cpoints[i] = sc.nextInt();
			}
			for(int i = 0;i<n;i++) {
				sum+=bpoints[dishes[i]-1];

			}
			for(int i = 1;i<n;i++) {
				if(dishes[i]-dishes[i-1]==1) {
					sum+=cpoints[dishes[i-1]-1];
				}
			}
			System.out.println(sum);
			sc.close();
		}
	public static void main(String[] args) {
		solve();

	}

}
