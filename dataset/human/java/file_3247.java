import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for(int i=0;i<2;i++){
      int rest = N %10;
      N = N / 10;
      if(rest == 9){
        System.out.println("Yes");
        return;
      }
    }
    System.out.println("No");
  }
}
