import java.util.Scanner;
public class Main {
	static int[][] gyo2=new int[100000][12];
	static int count=0;
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		long X=sc.nextLong();
		int C[]=new int[N];
		int A[][]=new int[N][M];
		for(int i=0;i<N;i++) {
			C[i]=sc.nextInt();
			for(int j=0;j<M;j++) {
				A[i][j]=sc.nextInt();
			}
		}
		int gyo[]=new int[N];
		zenbit(0,N,gyo);
		long ans=1000000000;
		boolean flag=true;
		boolean kuso=false;
		for(int i=0;i<count;i++) {
			int money=0;
			int kari[]=new int[M];
			for(int j=0;j<N;j++) {
			if(gyo2[i][j]==1) {
				for(int z=0;z<M;z++) {
				kari[z]+=A[j][z];
				}
				money+=C[j];
			}
				}
			for(int j=0;j<M;j++) {
				if(X>kari[j]) {
					flag=false;
					//System.out.println(money);
					//System.out.println(kari[j]);
				}
			}
			if(flag) {kuso=true;
			}
			if(flag&&(ans>money)) {
				ans=money;
			}
			flag=true;
		}
		if(kuso) {
			System.out.println(ans);
		}else {
			System.out.println(-1);
		}

}
	public static void zenbit(int kosu,int N,int gyo[]) {
		if(kosu<N) {
			gyo[kosu]=0;
			zenbit(kosu+1,N,gyo);
			gyo[kosu]=1;
			zenbit(kosu+1,N,gyo);
		}else {
			for(int i=0;i<N;i++) {
				gyo2[count][i]=gyo[i];
			}
			count++;
			return;
		}
	}

}
