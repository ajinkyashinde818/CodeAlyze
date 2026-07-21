import java.util.Scanner;
import java.util.Arrays;

public class Main{

	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);

		char s[]=sc.next().toCharArray();
		Arrays.sort(s);
		String ss=String.valueOf(s);
		if(ss.equals("abc")){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

	}
}
