import java.util.*;

class Main {
	Scanner sc;
	
	private void calc() {
		sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		System.out.println((long)A*B/extgcd(A, B)[0]);
	}
	static final int[] extgcd(int a, int b) {
		int aa = a, bb = b;
		int x0 = 1, x1 = 0;
		int y0 = 0, y1 = 1;
	
		while (b != 0) {
			int q = a / b;
			int r = a % b;
			int x2 = x0 - q * x1;
			int y2 = y0 - q * y1;
	
			a = b; b = r;
			x0 = x1; x1 = x2;
			y0 = y1; y1 = y2;
		}
		if (bb > 0 && x0 < 0) {
			int n = -x0/bb;
			if (-x0%bb != 0) n++;
			x0 += n*bb; y0 -= n*aa;
		}
	    return new int[]{a, x0, y0};
	}
	

	public static void main(String[] args) {
		new Main().calc();
	}
}
