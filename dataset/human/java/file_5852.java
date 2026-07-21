import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String words = sc.next();
    int ans = 0;
    words = words.replace("a","");
    if(words.length() == 2){
      words = words.replace("b","");
      if(words.length() == 1){
        words = words.replace("c","");
        if(words.length() == 0){
          ans = 1;
        }
      }
    }
    if(ans == 1){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
