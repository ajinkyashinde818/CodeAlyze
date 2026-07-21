import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	String s = scan.next();
	String t = scan.next();

	char[] s_ = s.toCharArray();
	char[] t_ = t.toCharArray();
	
	Arrays.sort(s_);
	Arrays.sort(t_);
	
	String s_asc = String.valueOf(s_);
	String t_asc = String.valueOf(t_);

	StringBuffer sb = new StringBuffer(t_asc);
	String t_desc = sb.reverse().toString();

	if(s_asc.compareTo(t_desc) < 0){
	    System.out.println("Yes");
	}else{
	    System.out.println("No");
	}
    }
}
