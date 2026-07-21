import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] S = sc.next().toCharArray();
    boolean foundA = false;
    boolean foundB = false;
    boolean foundC = false;
    for (char c : S) {
      if (c == 'a') {
        foundA = true;
      }
      if (c == 'b') {
        foundB = true;
      }
      if (c == 'c') {
        foundC = true;
      }
    }
    
    System.out.println(foundA && foundB && foundC ? "Yes" : "No");
  }
}
