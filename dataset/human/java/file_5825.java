import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String S =sc.next();
      	char[] s = S.toCharArray();
      	if(s[0]==s[1]||s[0]==s[2]||s[1]==s[2]){
        	System.out.println("No");
        }else{
        	System.out.println("Yes");
        }
 		sc.close();
	}
}
