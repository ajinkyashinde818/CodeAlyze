import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt();
		sc.close();
		int m=0;
		for(int i=0;i<N-1;i++)
		{
			if(i==0)
			{
				m=Math.max(m,A[i]-A[N-1]+K);
			}
			else
			{
				m=Math.max(m,(A[i+1]-A[i]));
			}
		}
		System.out.println(K-m);
	}

}
