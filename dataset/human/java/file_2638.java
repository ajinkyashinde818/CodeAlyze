import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    String ss[] = new String[s.length()];
    String tt[] = new String[t.length()];
    for(int i=0;i<s.length();i++){
      ss[i]=s.substring(i,i+1);
    }
    for(int i=0;i<t.length();i++){
      tt[i]=t.substring(i,i+1);
    }
    Arrays.sort(ss);
    Arrays.sort(tt);
    String smin ="";
    String tmax ="";
    for(int i=0;i<s.length();i++){
      smin=smin+ss[i];
    }
    for(int i=0;i<t.length();i++){
      tmax=tt[i]+tmax;
    }

    if(smin.compareTo(tmax)<0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
  

  
}
