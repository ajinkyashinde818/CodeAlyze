import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] n = sc.next().toCharArray();
		if (n[0]=='9' || n[1]=='9'){
        	System.out.print("Yes");
        }else{
			System.out.print("No");
        }
    }
}
