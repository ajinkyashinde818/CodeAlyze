import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		int N=sc.nextInt();

		int[] A=new int[N];

		for(int i=0;i<N;i++) A[i]=sc.nextInt();

		long ans=0;

		int cnt=0;

		for(int i=0;i<N;i++) {
			if(A[i]<=0) cnt++;
		}

		if(cnt%2==0) {
			for(int i=0;i<N;i++) ans+=Math.abs(A[i]);
		}else {
			int min=+1000000001;
			int index=0;
			for(int i=0;i<N;i++) {
				if(min>Math.abs(A[i])) {
					min=Math.abs(A[i]);
					index=i;
				}
			}
			for(int i=0;i<N;i++) {
				if(index==i) {
					if(A[i]<0) ans+=A[i];
					else ans+=-A[i];
				}
				else ans+=Math.abs(A[i]);
			}
		}

		System.out.println(ans);

		sc.close();

	}

}
