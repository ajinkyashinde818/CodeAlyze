import java.util.Scanner;
import java.util.Arrays;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    char[] in = sc.next().toCharArray();
    Arrays.sort(in);
    System.out.println(new String(in).equals("abc") ? "Yes" : "No");
  }
}
