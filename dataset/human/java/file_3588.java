import java.util.*;

public class Main{
	public static void main(String[] args){
      Scanner scanner = new Scanner(System.in);
      String tokens[] = scanner.nextLine().split(" ");
      
      int x = tokens[0].charAt(0);
      int y = tokens[1].charAt(0);
      
      if(x>y){
        System.out.println(">");
      }
      else if(x == y){
        System.out.println("=");
      }
      else{
        System.out.println("<");
      }
    }
}
