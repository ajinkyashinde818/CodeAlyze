import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String str = scanner.next();
    char s0 = str.charAt(0);
    char s1 = str.charAt(1);
    char s2 = str.charAt(2);

    if(s0 == s1 || s1 == s2 || s2 == s0){
      System.out.println("No");
    } else{
      System.out.println("Yes");
    }
  }
}
