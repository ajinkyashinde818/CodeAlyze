import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static Scanner scanner;
    static int min=Integer.MAX_VALUE;
    static long G;
    static long[] P;
    static long[] C;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    int D=gi();
	    G=gl();
	    P=new long[D];
	    C=new long[D];
	    for (int i=0; i<D;i++) {
	    	P[i]=gl();
	    	C[i]=gl();
	    }


        List<Integer> l= new ArrayList<Integer>();
        f(l, D);
        System.out.println(min);
//	    if(max>s-max) {
//	    	System.out.println(s-max-1);
//	    }
	}

	public static void f(List<Integer> l, int n) {
		if(l.size()==n) {
			long score=0;
			int c=0;
			for (int i=0; i<n;i++) {
				int index=l.get(i);
				if(index*100*P[index-1] +C[index-1] >=G-score) {
				    for (int j=0; j<P[index-1]; j++) {
					    score+=index*100;
					    c++;
					    if(j==P[index-1]-1) score+=C[index-1];
				    	if(score>=G) {
						    if (c<min)min=c;
					    	return;
				    	}
			    	}
				} else {
					score +=index*100*P[index-1] +C[index-1];
					c+=P[index-1];
				}
			}
			return;
		}
		for (int i=1; i<=n;i++) {
			if (!l.contains(i)) {
				List<Integer> nl=new ArrayList<Integer>();
				nl.addAll(l);
				nl.add(i);
				f(nl, n);
			}
		}
	}

	// 文字列として入力を取得
	public static String gs() {
		return scanner.next();
	}

	// intとして入力を取得
	public static int gi() {
		return Integer.parseInt(scanner.next());
	}

	// longとして入力を取得
	public static long gl() {
		return Long.parseLong(scanner.next());
	}

	// doubleとして入力を取得
	public static double gd() {
		return Double.parseDouble(scanner.next());
	}
}
