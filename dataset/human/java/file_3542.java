import java.util.*;
public class Main{

  public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String x = sc.next();
      String y = sc.next();
      if(x.equals(y)){
        System.out.println("=");
      	return;
      }
     
      System.out.println(x.compareTo(y) > 0 ? ">" : "<");
  }
}
