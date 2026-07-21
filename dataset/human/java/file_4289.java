import java.util.Scanner;

public class Main {

	static Scanner scanner;

	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    int N=gi();
	    int[] A=new int[N];
	    int[] B=new int[N];
	    int[] C=new int[N-1];
	    
	    for(int i=0; i<N; i++) {
	    	A[i]=gi();
	    }
	    for(int i=0; i<N; i++) {
	    	B[i]=gi();
	    }
	    for(int i=0; i<N-1; i++) {
	    	C[i]=gi();
	    }
	    
	    int b=-1;
	    int m=0;
	    for (int i=0; i<N; i++) {
	    	int a=A[i];
	    	m+=B[a-1];
	    	if(b!=-1 && a-b==1) {
	    		m+=C[b-1];
	    	}
	    	b=a;
	    }
        System.out.print(m);
//        if (c<=2) {
//        	System.out.println("YES");
//        }else {
//        	System.out.println("NO");
//        }
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
