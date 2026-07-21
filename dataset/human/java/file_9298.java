import java.util.Scanner;

	public class Main {
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);

			int n = sc.nextInt();
			int[][] d = new int[n][2];
			int count = 0;
			boolean ans=false;
			for(int i=0;i<n;i++) {
				d[i][0] = sc.nextInt();
				d[i][1] = sc.nextInt();
			}

			for(int i=0;i<n;i++) {

				if(d[i][0]==d[i][1]) {
					count++;
				}else {
					count=0;
				}if(count >= 3) {
					ans=true;}
			}
			if(ans) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}


		}
	}
