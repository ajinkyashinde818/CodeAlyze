import java.util.Scanner;

class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

	int N, R;
	N = sc.nextInt();
	R = sc.nextInt();

	if (N >= 10) {
	    System.out.println(R);
	} else {
	    System.out.println(R + 100 * (10 - N));
	}
    }
}
