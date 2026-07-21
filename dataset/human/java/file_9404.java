import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();

	    boolean retflg = false;
	    int c = 0;
	    for (int i = 0; i < n; i++) {
	    	int d1 = sc.nextInt();
	    	int d2 = sc.nextInt();
	    	if (d1 == d2) {
	    		c++;
	    	} else {
	    		c = 0;
	    	}
	    	if (c >= 3) {
	    		retflg = true;
	    		break;
	    	}
	    }
	    if (retflg) {
	    	System.out.println("Yes");
	    } else {
	    	System.out.println("No");
	    }
	}

}
