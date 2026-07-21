import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
        Scanner sc=new Scanner(System.in);
        char x=sc.next().charAt(0);
        char y=sc.next().charAt(0);
         if(x>y)System.out.println(">");
         else if(x<y)System.out.println("<");
         else System.out.println("=");
        
	
	}

}
