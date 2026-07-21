import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        
        Arrays.sort(s);
        Arrays.sort(t);
        for (int i = 0; i < t.length/2; i++) {
        	char c = t[i];
        	t[i] = t[t.length-1-i];
        	t[t.length-1-i] = c;
        }
        
        if (new String(s).compareTo(new String(t)) < 0) {
        	System.out.println("Yes");
        } else {
        	System.out.println("No");
        }
        
    }
    
}
