import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int ans = 0;
    int n = 0;
    int K = 0;
    if(a > b){
      for(int i = 1;i <= a;i++){
        if(a%i == 0){
          n = a/i;
          if(b%n == 0){
            K++;
            if(k == K) break;
          }
        }
      }
    }
    else if(a < b){
      for(int i = 1;i <= b;i++){
        if(b%i == 0){
          n = b/i;
          if(a%n == 0){
            K++;
            if(k == K) break;
          }
        }
      }
    }
    else{
      for(int i = 1;i <= a;i++){
        if(a%i == 0){
          n = a/i;
          if(b%n == 0){
            K++;
            if(k == K) break;
          }
        }
      }
    }
    System.out.println(n);
  }
}
