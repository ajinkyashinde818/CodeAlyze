import java.util.*;
public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int r = sc.nextInt();
    int a = 0;

    if(n>=10){
      System.out.println(r);
    }else{
      a = r+(100*(10-n));
      System.out.println(a);
    }
  }
}
