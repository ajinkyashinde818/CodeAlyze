import java.util.*;

public class Main {
	  public static void main(String args[]){
      	Scanner scan = new Scanner(System.in);
            
        String n = scan.next();
        
        String first_num = n.substring(0,1);
        String second_num = n.substring(1,2);
        
        if( first_num.charAt(0) == '9' || second_num.charAt(0) == '9' )System.out.println("Yes");
        else System.out.println("No");
            
        
	  }
}
