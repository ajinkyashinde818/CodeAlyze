import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int M = scn.nextInt();
		Ship[] S = new Ship[M];
		for(int i = 0;i < M;i++) {
			S[i] = new Ship(scn.nextInt(), scn.nextInt());
		}
		Arrays.sort(S);

		boolean[] Go = new boolean[N];
		for(int i = 0;i < M;i++) {
			if(S[i].getA() == 1) {
				Go[S[i].getB()-1] = true;
			}
			if(S[i].getB()==N) {
				if(Go[S[i].getA()-1])Go[N-1] = true;
			}
			if(Go[N-1])break;
		}


		System.out.println(Go[N-1]?"POSSIBLE":"IMPOSSIBLE");
	}

}

class Ship implements Comparable<Ship>{
	int a;
	int b;

	Ship(int a, int b){
		this.a = a;
		this.b = b;
	}

	@Override
	public int compareTo(Ship o) {
		if(this.a > o.getA())return 1;
		if(this.a < o.getA())return -1;
		return 0;
	}

	public int getA() {
		return a;
	}
	public int getB() {
		return b;
	}

}
