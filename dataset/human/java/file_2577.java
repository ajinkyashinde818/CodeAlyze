import java.util.*;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String S[] = sc.next().split("");
    String T[] = sc.next().split("");
    
    Arrays.sort(S);
    Arrays.sort(T, Collections.reverseOrder());
    
    String newS = String.join("", S);//文字列の連結
    String newT = String.join("", T);//文字列の連結
    
    //System.out.println(newS);
    //System.out.println(newT);
    
    if(newS.equals(newT)){
      System.out.println("No");
      return;
    }
    
    String s[] = {newS, newT};
    Arrays.sort(s);
    
    if(s[0]==newS){
      System.out.println("Yes");      
    }else{
      System.out.println("No");      
    }
  }
}
