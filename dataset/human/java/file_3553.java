import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();
    if(str1.charAt(0) < str2.charAt(0)){
      System.out.println('<');
    }else if(str1.charAt(0) > str2.charAt(0)){
      System.out.println('>');
    }else{
      System.out.println('=');
    }
  }
}
