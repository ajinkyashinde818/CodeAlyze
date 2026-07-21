import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){

			int N = scan.nextInt();
			int[][]D = new int[N][2];
			int[]che = new int[N];


			int count = 0;
			int renzoku = 0;
			for(int i = 0;i<N;i++) {
				D[i][0] = scan.nextInt();
				D[i][1] = scan.nextInt();

				if(D[i][0]==D[i][1]) {
					che[i]++;
				}
			}

			int ok = 0;

			for(int i = 0;i<N-2;i++) {
				if(D[i][0]==D[i][1]&&D[i+1][0]==D[i+1][1]&&D[i+2][0]==D[i+2][1]) {
					ok=1;
				}
			}

			if(ok==1) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}




		}


	}




}
