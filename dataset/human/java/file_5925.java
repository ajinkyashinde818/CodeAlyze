import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String c = sc.next();
    
    if("abc".equals(c) || "acb".equals(c) || "bac".equals(c) || "bca".equals(c) || "cab".equals(c) || "cba".equals(c)){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
