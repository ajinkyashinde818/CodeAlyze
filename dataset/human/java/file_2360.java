import java.util.*;

public class Main{
	
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
  	String s=sc.next();
    StringBuffer sb=new StringBuffer(s);
    sb.reverse();
    s=sb.toString();
    String t=s.replaceFirst("LAVITSEF","");
    StringBuffer sb2=new StringBuffer(t);
    sb2.reverse();
    
    System.out.print(sb2);
  }
}
