import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    if(N<10){
      M += 100*(10-N);
    }
    System.out.println(M);
  }
}
