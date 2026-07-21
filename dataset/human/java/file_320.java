import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int A[]=new int[N];
		int z=0,y=0;
		long ans=0;
		while(z<N){
			A[z]=stdIn.nextInt();
			if(A[z]<0){
				A[z]*=-1;
				y++;
			}
			ans+=A[z];
			z++;
		}
		Arrays.sort(A);
		if(y%2==1)
			ans-=A[0]*2;
		System.out.println(ans);
	}
}
