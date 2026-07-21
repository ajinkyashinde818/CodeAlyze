import java.util.Scanner;
public class Main {
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		long K=sc.nextLong();
		int A[]=new int[N];
		for(int i=0;i<N;i++) {
			A[i]=sc.nextInt();
		}
		if(A[0]==1) {
			System.out.println(1);
			System.exit(0);
		}
		int B[]=new int[N];
		int next=0;
		long loop=0;
		for(int i=0;i<K;i++) {
			if(B[next]==0) {
			B[next]=i+1;
			next=A[next]-1;
			K--;
					}else {
						loop=i+1-B[next];
						K%=loop;
						break;
					}

		}
		for(int i=0;i<K;i++) {
			next=A[next]-1;
		}
		System.out.println(next+1);

}
}
