import java.util.Scanner;

public class Main {
    public static void main(final String[] args) {
    	Scanner s = new Scanner(System.in);
    	int n = s.nextInt();
    	int cnt = 0;
    	boolean flag = false;
    	while(n-->0) {
    		int a = s.nextInt(), b = s.nextInt();
    		if (a == b) {
    			cnt++;
    		}else {
    			cnt = 0;
    		}
    		if (cnt >= 3) {
    			flag = true;
    		}
    	}
    	if (flag) {
    		System.out.println("Yes");
    	}else {
    		System.out.println("No");
    	}
    }
}
