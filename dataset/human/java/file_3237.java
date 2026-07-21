import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private final int N;

    public Main() {
	N = Integer.parseInt(scan.next());

	scan.close();
    }

    public final void answer() {
	int a0 = N % 10;
	int a1 = N / 10;

	System.out.println(a0 == 9 || a1 == 9 ? "Yes" : "No");
    }
}
