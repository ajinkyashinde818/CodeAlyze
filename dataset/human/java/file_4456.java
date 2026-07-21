import java.util.*;

class Main{
	
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int K = A+B+1;
		int X = K;
		if(X>C) X = C;

		System.out.println(B+X);

	}
}
