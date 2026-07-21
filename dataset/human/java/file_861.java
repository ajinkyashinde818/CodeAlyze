import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	try {
    		final int N = sc.nextInt();
    		final int R = sc.nextInt();

    		if (N >= 10) {
    			System.out.println(R);
    		} else {
    			System.out.println(R+100*(10-N));
    		}

    	} finally {
    		sc.close();
    	}
    }
}
