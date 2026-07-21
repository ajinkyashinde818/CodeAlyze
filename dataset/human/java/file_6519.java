import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String[] T = sc.nextLine().split(" ");
    int K = Integer.parseInt(T[0]);
    int S = Integer.parseInt(T[1]);
    
    int ans = 0;
    for(int i = 0; i <= K; i++){
      for(int j = 0; j <= K; j++){
        int k = S-i-j;
        if(i+j+k == S && k >= 0 && k <= K){
          ans++;
        }
      }
    }
    System.out.println(ans);
  }
}
