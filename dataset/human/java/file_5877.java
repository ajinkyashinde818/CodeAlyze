import java.util.*;

public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String abc[] = s.split("");
    Arrays.sort(abc);
    if(abc[0].equals("a") && abc[1].equals("b") && abc[2].equals("c")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
