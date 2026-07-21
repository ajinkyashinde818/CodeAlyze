import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int K=sc.nextInt();
		int S=sc.nextInt();
		long toori=0;

		if(K<=200) {
			for(int i=0; i<=K; i++) {
				for(int j=0; j<=K; j++) {
					for(int k=0; k<=K; k++) {
						if(i+j+k==S) {
							toori++;
						}
					}
				}
			}
			System.out.println(toori);
		}
		else {
			if(S<=K) {
				System.out.println((S+2)*(S+1)/2);
			}
			else if(S>K && S<=2*K) {
				System.out.println((S+2)*(S+1)/2-3*(S-K+1)*(S-K)/2);

			}
			else if(S>2*K) {
				int tmp=3*K-S;
				System.out.println((tmp+2)*(tmp+1)/2);
			}
		}

	}
}
