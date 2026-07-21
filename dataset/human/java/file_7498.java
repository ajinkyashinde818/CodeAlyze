import java.util.Scanner;
 
public class Main{
	public static void main(String args[])throws Exception{
 
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		S = S.replaceAll("eraser","");
		S = S.replaceAll("erase","");
		S = S.replaceAll("dreamer","");
		S = S.replaceAll("dream","");
		if(S.equals("")) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}
