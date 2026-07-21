import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    char[] sp = s.toCharArray();
    char[] tp = t.toCharArray();
    Arrays.sort(sp);
    Arrays.sort(tp);
    s="";
    t="";
    for(int i=0;i<sp.length;i++) s+=sp[i];
    for(int i=tp.length-1;i>=0;i--) t+=tp[i];
    //System.out.println(s+" "+t);
    int ans= t.compareTo(s);
    if(ans>0) System.out.println("Yes");
    else System.out.println("No");
  }
}
