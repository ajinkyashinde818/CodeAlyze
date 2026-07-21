import java.util.*;
 
public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
      	boolean isContained = false;
      	for(int i = 0; i < s.length(); i++) {
        	if(s.contains("a") && s.contains("b")
               && s.contains("c")) isContained = true;
        }
      	if(isContained) {
        	System.out.println("Yes");  
        } else {
        	System.out.println("No");  
        }
	}
}
