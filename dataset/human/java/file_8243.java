import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();

		System.out.println(lcm(A, B));
	}

	public static long lcm(int A, int B){
		int temp;
		long C = A;
		C *= B;
		while((temp = A%B) != 0){
			A = B;
			B = temp;
		}
		return (C / B);
	}
}
