import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private final int N;
    private final int M;
    private final boolean[] from1;
    private final boolean[] toN;

    public Main() {
	N = Integer.parseInt(scan.next());
	M = Integer.parseInt(scan.next());
	from1 = new boolean[N];
	toN = new boolean[N];
	for (int i = 0; i < M; i++) {
	    int a = Integer.parseInt(scan.next()) - 1;
	    int b = Integer.parseInt(scan.next()) - 1;
	    if(a == 0) from1[b] = true;
	    if(b == N-1) toN[a] = true;
	}

	scan.close();
    }

    public final void answer() {
	boolean ans = false;
	for (int i = 0; i < N; i++) {
	    if(from1[i] && toN[i]) {
		ans = true;
		break;
	    }
	}
	System.out.println(ans ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
