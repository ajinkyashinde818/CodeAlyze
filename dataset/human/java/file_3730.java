import java.util.*;

public class Main{
	public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        
        int X = Integer.parseInt(a,16);
        int Y = Integer.parseInt(b,16);

        if(X < Y){
            System.out.println("<");
        }else if(X > Y){
            System.out.println(">");
        }else{
            System.out.println("=");
        }

		
		
	}
}
