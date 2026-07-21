import java.util.Scanner;
public class Main {
	public static void main(String[] args)throws Exception{
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int K=stdIn.nextInt();
		int S=stdIn.nextInt();
		int A[]=new int[N];
		for(int i=0;i<N;i++){
			if(i<K)
				A[i]=S;
			else
				if(S==1000000000)
					A[i]=999999999;
				else
					A[i]=1000000000;
			System.out.println(A[i]);
		}
	}
}
