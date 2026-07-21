import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String c = sc.next();
    String h[] = new String[3];
    h[0]=c.substring(0,1);
    h[1]=c.substring(1,2);
    h[2]=c.substring(2,3);
    Arrays.sort(h);
    if(h[0].equals("a")&&h[1].equals("b")&&h[2].equals("c")){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
  

  
}
