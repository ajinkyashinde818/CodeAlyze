import java.util.Scanner;

public class Main {

	static Scanner scanner;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    int n=gi();
	    int m=gi();
	    String[] A=new String[n];
	    String[] B = new String[m];
	    
	    for (int i=0; i<n; i++) {
	    	A[i]=gs();
	    }
	    for (int i=0; i<m; i++) {
	    	B[i]=gs();
	    }
	    
	    for (int i=0; i<n-m+1; i++) {
	    	for (int j=0; j<n-m+1; j++) {
	    		boolean f=true;
	    		for (int k=0; k<m; k++) {
	    			for (int l=0; l<m; l++) {
	    			    if(A[j+l].charAt(k+i) != B[l].charAt(k)) {
	    			    	f=false;
	    			    	break;
	    			    }
    			    }
	    			if(!f) {
	    				break;
	    			}
    		    }
	    		if (f) {
	    			System.out.print("Yes");
	    			return;
	    		}
	 	    }
	    }

        System.out.println("No");
//        if (a<=8&&b<=8) {
//        	System.out.print("Yay!");
//        }else {
//        	System.out.print(":(");
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
