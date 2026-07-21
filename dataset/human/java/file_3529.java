import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	char l = sc.next().charAt(0); 
    char r = sc.next().charAt(0);
    if (l < r) {
      System.out.println('<');
    } else if (l > r) {
      System.out.println('>'); 
    } else {
      System.out.println('=');
    }
  }
}
