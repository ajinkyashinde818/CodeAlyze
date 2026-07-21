import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc =new Scanner(System.in);
    int N=sc.nextInt();
    int R =100*Math.max(0,10-N)+sc.nextInt();
    System.out.println(R);
  }
}
