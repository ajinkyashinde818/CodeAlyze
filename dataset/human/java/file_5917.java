import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String S = sc.next();

  if(S.contains("abc") || S.contains("acb") || S.contains("bac") || S.contains("bca") || S.contains("cab") || S.contains("cba")){
    System.out.println("Yes");
  }else{
    System.out.println("No");
  }

  }
}
