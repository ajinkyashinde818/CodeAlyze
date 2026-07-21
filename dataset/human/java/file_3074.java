import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();

		boolean[] start=new boolean[N+1];
		boolean[] goal=new boolean[N+1];

		for(int i=0; i<N+1; i++) {
			start[i]=false;
			goal[i]=false;
		}

		int tmp1=0;
		int tmp2=0;
		for(int i=0; i<M; i++) {
			tmp1=sc.nextInt();
			tmp2=sc.nextInt();
			if(tmp1==1) {
				start[tmp2]=true;
			}

			else if(tmp2==N) {
				goal[tmp1]=true;
			}
		}

		for(int i=2; i<=N-1; i++) {
			if(start[i]==true && goal[i]==true) {
				System.out.println("POSSIBLE");
				System.exit(0);
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
