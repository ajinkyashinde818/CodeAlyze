import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long calA = A;
		long calB = B;
		long tmp;
		while (true) {
			tmp = calB;
			calB = calA%calB;
			calA = tmp;
			if (calB == 0) {
				break;
			}
		}
		System.out.println(A * B / tmp);
	}
}
