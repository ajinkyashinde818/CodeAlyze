import java.util.Scanner;
public class Main{
	public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	String s=sc.next();

	if(s.contains("eraser")) {
		s=s.replace("eraser", "");
	}
	if(s.contains("erase")) {
		s=s.replace("erase", "");
	}
	if(s.contains("dreamer")) {
		s=s.replace("dreamer", "");
	}
	if(s.contains("dream")) {
		s=s.replace("dream", "");
	}
	
	System.out.println(s.equals("")?"YES":"NO");
	}
}
