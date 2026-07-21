import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    String S = sc.next();
    char[] c = new char[3];

    for(int i = 0 ; i < S.length() ; i ++){
      c[i] = S.charAt(i) ;
    }

    boolean result = (c[0] != c[1]) && (c[1] != c[2]) && (c[2] != c[0]);

    System.out.println(result ? "Yes" : "No" );
  }
}
