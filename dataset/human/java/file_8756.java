import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int a,b,k;
    	
    	a = in.nextInt();
    	b = in.nextInt();
    	k = in.nextInt();
    	
//    	int div = Math.abs(a-b);
//    	if (div == 0) {
//    		div = a;
//    	}
    	int counter = 0;
    	
    	for (int i = a; i > 0; i--) {
    		if (a % i == 0 && b % i == 0) {
    			counter++;
    			if (counter == k) {
    				System.out.println(i);
    				return;
    			}
    		}
    	}
    	
    }

  }
