import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next(),t = sc.next();
    char[] sch = s.toCharArray();
    char[] tch = t.toCharArray();
    Arrays.sort(sch);
    Arrays.sort(tch);
    int slen = s.length(),tlen = t.length();
    s = "";t = "";
    for(int i = 0;i<slen;i++){
      s = s + sch[i] ;
    }
    for(int i = 0;i<tlen;i++){
      t = tch[i] + t;
    }
    if(t.compareTo(s) > 0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }


  }
}
