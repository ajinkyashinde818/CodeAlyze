import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		String S = stdIn.next();
		StringBuffer str = new StringBuffer(S);
        S = str.reverse().toString();
        
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        for(int i = 0; i < 4; i++) {
        	StringBuffer d = new StringBuffer(divide[i]);
        	divide[i] = d.reverse().toString();
        }
        
        boolean can = true;
        for(int i = 0; i < S.length();) {
        	boolean flag = false;
        	for(int j = 0; j < 4; j++) {
        		String d = divide[j];
        		if(i+d.length() <= S.length() && S.substring(i, i+d.length()).equals(d)) {
        			flag = true;
        			i += d.length();
        		}
        	}
        	if(!flag) {
        		can = false;
        		break;
        	}
        }
        if(can) System.out.println("YES");
        else System.out.println("NO");

	}

}
