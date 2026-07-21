import java.util.*;

class Main {
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    
    String s = sc.next();
    
    boolean tf = s.replaceAll("[^a]", "").length() > 0 && s.replaceAll("[^b]", "").length() > 0 && s.replaceAll("[^c]", "").length() > 0;
    if(tf) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
