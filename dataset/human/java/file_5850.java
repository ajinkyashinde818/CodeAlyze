import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	String S = scan.next();
	char[] chars = S.toCharArray();

	Arrays.sort(chars);

	S = String.valueOf(chars);

	if(S.equals("abc")){
	    System.out.println("Yes");
	}else{
	    System.out.println("No");
	}
    }
}
