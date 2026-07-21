import java.util.Scanner;
public class Main {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int K=sc.nextInt();
		int N=(sc.nextInt());
		int A[]=new int[N];
		int max=0;
		int maxi=0;
		A[0]=sc.nextInt();
		for(int i=1;i<N;i++) {
			A[i]=sc.nextInt();
			if(max<A[i]-A[i-1]) {
				max=A[i]-A[i-1];
				maxi=i;
			}
		}
		if(K-(A[N-1]-A[0])>max) {
			maxi=0;
			max=K-(A[N-1]-A[0]);
		}
		System.out.println(K-max);
	}
}
