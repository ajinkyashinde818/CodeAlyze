import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s =  sc.next();
    String t =  sc.next();
    String s1[] = s.split("",0);
    String t1[] = t.split("",0);
    Arrays.sort(s1);
    Arrays.sort(t1,Comparator.reverseOrder());
    s = String.join("",s1);
    t = String.join("",t1);
    if(s.compareTo(t)<0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
