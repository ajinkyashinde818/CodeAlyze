import java.util.*;
public class Main {
	/*
	 * A+B >= B+C
	 * A+B < C -> A+B+B+1
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		if(A+B>=C) System.out.println(B+C);
		else System.out.println(A+2*B+1);
	}
}
