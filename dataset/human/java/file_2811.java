import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();;
    char[] t = sc.next().toCharArray();;
    Arrays.sort(s);
    String sAfter = new String(s);
    Arrays.sort(t);
    String tAfter = new String(t);
    StringBuffer str = new StringBuffer(tAfter);
    tAfter = str.reverse().toString();
    if(sAfter.compareTo(tAfter)<0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
