import java.util.*;

public class Main{

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.next());
    int r = Integer.parseInt(sc.next());

    if (n>=10)
      System.out.println(r);
    else
      System.out.println(r + 100*(10-n));

  }
}
