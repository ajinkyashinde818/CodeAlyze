import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String x = sc.next();
    String y = sc.next();
    String ans[] = {"<", "=", ">"};
    if (x.compareTo(y)<0){
      System.out.println("<");
    }else if (x.compareTo(y)==0){
      System.out.println("=");
    }else{
      System.out.println(">");
    }
  }
}
