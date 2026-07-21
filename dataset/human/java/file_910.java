import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt();
    int b = scan.nextInt();
    if (a >= 10){
      System.out.println(b);
    }
    else{
      int g = 10-a;
      System.out.println(g*100+b);
    }
  }
}
