import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){

			long N = scan.nextLong();
			long K = scan.nextLong();
			long S = scan.nextLong();


			long count = 0;

			for(int i = 0;i<K;i++) {
				if(i==K-1&&K== N) {
					System.out.print(S);
				}else {

					System.out.print(S+" ");
				}
			}
			for(long i= K;i<N;i++) {

				if(i==N-1) {
					if(S!=1000000000)
						System.out.print((S+1));
					else
						System.out.print(1);

				}else {
					if(S!=1000000000)
					System.out.print((S+1)+" ");
					else
						System.out.println(1);
				}




				}


		}


	}


}
