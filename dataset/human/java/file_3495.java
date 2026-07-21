import java.util.Scanner;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    char X = sc.next().toCharArray()[0];
    char Y = sc.next().toCharArray()[0];
    if(X < Y){
      System.out.println("<");
    }
    else if (X == Y){
      System.out.println("=");
    }
    else{
      System.out.println(">");
    }
  }
}
