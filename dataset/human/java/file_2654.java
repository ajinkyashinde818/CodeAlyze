import java.util.Arrays;
import java.util.Scanner;

public class Main {
  
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    
    String s = sc.next();
    String t = sc.next();
    
    char sArray[] = new char[s.length()];
    for (int i = 0; i < s.length(); i++) {
      sArray[i] = s.charAt(i);
    }
    Arrays.sort(sArray);
    char tArray[] = new char[t.length()];
    for (int i = 0; i < t.length(); i++) {
      tArray[i] = t.charAt(i);
    }
    Arrays.sort(tArray);
    char tReverse[] = new char[t.length()];
    for (int i = 0; i < t.length(); i++) {
      tReverse[i] = tArray[t.length() - 1 - i];
    }
    
    String sF = String.valueOf(sArray);
    String tR = String.valueOf(tReverse);
    
    if (tR.compareTo(sF) > 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
    
  }
}
