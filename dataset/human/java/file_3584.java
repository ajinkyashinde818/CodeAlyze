import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.next().charAt(0);
    int y = sc.next().charAt(0);
    if(x>y){
      System.out.print(">");
    }else if(x<y){
      System.out.print("<");
    }else{
      System.out.println("=");
    }
  }
}
