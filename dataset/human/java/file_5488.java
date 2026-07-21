import java.util.*;

public class Main {
	  public static void main(String args[]){
      	Scanner scan = new Scanner(System.in);
            
        int x = scan.nextInt();
        String cnt;
        
        if( x < 1200 )cnt = "ABC";
        else cnt = "ARC";
        
        System.out.println(cnt);
	  }
}
