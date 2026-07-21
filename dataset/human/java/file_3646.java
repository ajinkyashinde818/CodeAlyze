import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    String x = sc.next();
    String y = sc.next();
    
    int xNum = 0;
    int yNum = 0;
    
    if (x.equals("A")) {
      xNum = 10;
    } else if (x.equals("B")) {
      xNum = 11;
    } else if (x.equals("C")) {
      xNum = 12;
    } else if (x.equals("D")) {
      xNum = 13;
    } else if (x.equals("E")) {
      xNum = 14;
    } else if (x.equals("F")) {
      xNum = 15;
    }
    
    if (y.equals("A")) {
      yNum = 10;
    } else if (y.equals("B")) {
      yNum = 11;
    } else if (y.equals("C")) {
      yNum = 12;
    } else if (y.equals("D")) {
      yNum = 13;
    } else if (y.equals("E")) {
      yNum = 14;
    } else if (y.equals("F")) {
      yNum = 15;
    }
    
    if (xNum == yNum) {
      System.out.println("=");
    } else if (xNum < yNum) {
      System.out.println("<");
    } else if (xNum > yNum) {
      System.out.println(">");
    }
  }
}
