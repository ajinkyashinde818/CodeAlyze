import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s="ABCDEF";
    String a=sc.next();
    String b=sc.next();
    if(s.indexOf(a)<s.indexOf(b)){
      System.out.println("<");
    }else if(s.indexOf(a)==s.indexOf(b)){
      System.out.println("=");
    }else if(s.indexOf(a)>s.indexOf(b)){
      System.out.println(">");
    }
  }
}
