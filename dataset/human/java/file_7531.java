import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static String[] str = {
		"eraser",
		"erase",
		"dreamer",
		"dream",
	};
	
	public static void main (String[] args) {
   	 Scanner sc = new Scanner(System.in);
   	 String S = sc.nextLine();
   	 S = S.replaceAll(str[0], "-");
   	 S = S.replaceAll(str[1], "-");
   	 S = S.replaceAll(str[2], "-");
   	 S = S.replaceAll(str[3], "-");
   	 S = S.replaceAll("-", "");
   	 if(S.length() == 0) {
   		 System.out.println("YES");
   	 } else {
   		 System.out.println("NO");   		 
   	 }
    }
}
