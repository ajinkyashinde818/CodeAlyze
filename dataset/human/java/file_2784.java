import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      char[] sArr = s.toCharArray();
      Arrays.sort(sArr);

      String t = sc.next();
      char[] tArr = t.toCharArray();
      Arrays.sort(tArr);
      int i = 0, j = tArr.length - 1;
      while(i < sArr.length && j >= 0) {
        if(sArr[i] > tArr[j]) {
          System.out.println("No");
          return;
        } else if(sArr[i] < tArr[j]) {
          System.out.println("Yes");
          return;
        } else {
            i++; j--;
        }
      }
      if(i == sArr.length && j >= 0)
        System.out.println("Yes");
      else
        System.out.println("No");
  }
}
