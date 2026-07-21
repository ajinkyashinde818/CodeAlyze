import java.util.*;

public class Main{
	public static void main(String[] args){
      Scanner scanner = new Scanner(System.in);
      String str = scanner.next();
      
      if(str.indexOf('9') != -1){
		System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }   
	}
}
