import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int A = Integer.parseInt(sc.next());
    int B = Integer.parseInt(sc.next());
    int K = Integer.parseInt(sc.next());
    
    int ans = 0;
    int count = 0;
    for(int i = 100; i >= 1; i--){
      if(A%i == 0 && B%i == 0){
        ans = i;
        count++;
      }
      if(count == K){
        break;
      }
    }
    
    System.out.println(ans);
  }
}
