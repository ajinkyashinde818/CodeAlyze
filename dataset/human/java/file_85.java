import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i=0;i<N;i++) {
			A[i]=sc.nextInt();
		}
		long sum=0;
		int cnt=0;
		int zero_cnt=0;
		int min=1_000_000_005;
		for (int i=0;i<N;i++) {
			int tmp=Math.max(A[i],-A[i]);
			sum+=tmp;
			if (A[i]<0) {
				cnt++;
			}
			if (A[i]==0) {
				zero_cnt++;
			}
			min=Math.min(min,tmp);
		}
		if (zero_cnt==0 && cnt%2==1) {
			sum-=min*2;
		}
		System.out.println(sum);
	}
}
