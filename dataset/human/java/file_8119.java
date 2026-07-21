import java.util.Scanner;
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long A = sc.nextInt();
		long B = sc.nextInt();
		long pile = 1;
		
		for(long i=2; i<=Math.min(A, B);i++) {
			if(A%i==0 && B%i==0) {
				A /= i;
				B /= i;
				pile *= i;
				i--;
			}
        }
      long answer = A*B*pile;
      System.out.println(answer);
    }
}
