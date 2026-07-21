import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int S = sc.nextInt();
    int ans = 0;
    int sum = 0;
    
    for(int i=0; i<=K; i++){
      for(int j=0; j<=K; j++){
        sum = S-(i+j);
        if(0 <= sum && sum <= K){
          ans++;
        }
      }
    }
    System.out.println(ans);
  }
}
