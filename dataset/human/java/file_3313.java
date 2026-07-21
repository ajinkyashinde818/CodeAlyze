import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s[] = sc.next().split("");
    if (s[0].equals("9") || s[1].equals("9")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
