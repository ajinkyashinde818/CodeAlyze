import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    char[] c=sc.next().toCharArray();
    Arrays.sort(c);
    String s=String.valueOf(c);
    if(s.equals("abc")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
