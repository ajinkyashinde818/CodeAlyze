import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	static Scanner scanner;
	static int[] C;
	static int[][] A;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    int n=gi();
	    int m=gi();
	    int x=gi();
	    C=new int[n];
	    A = new int[n][m];
	    
	    int c=Integer.MAX_VALUE;
	    for (int i=0; i<n; i++) {
	    	C[i] = gi();
	    	for (int j=0; j<m;j++) {
	    		A[i][j]=gi();
	    	}
	    }
	    
	    for (int i=0; i<Math.pow(2, n); i++) {
	    	int t=f(n,m,x,i);
	    	if (t>=0 && t<c) {
	    		c=t;
	    	}
	    }
	    
	  if (c!=Integer.MAX_VALUE) {
	    System.out.println(c);
	  } else {
		  System.out.println(-1);
	  }
	    
        //System.out.println(Math.pow(l/3, 3));
//        if (a<b) {
//        	System.out.print(Math.max(b-a-w, 0));
//        }else {
//        	System.out.print(Math.max(a-b-w, 0));
//        }


	}

	public static int f(int n, int m, int x, int y) {
		int c=0;
		int[] e= new int[m];
	    for (int i=0; i<n; i++) {
	        if(((y & (int)Math.pow(2, i)) >> i) == 1) {
	        	c+=C[i];
	        	for (int j=0; j<m;j++) {
	        		e[j]+=A[i][j];
	        	}
	        }
	    }
	    for (int i=0;i<m;i++) {
	    	if (x>e[i]) {
	    		return -1;
	    	}
	    }
	    return c;
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
