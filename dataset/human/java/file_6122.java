import java.util.*;
 
class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int k = sc.nextInt();
    int s = sc.nextInt();
    int ans = 0, sum = 0;
    for(int i=0; i<=k; i++){
      for(int j=0; j<=k; j++){
        sum = s-i-j;
        if(0 <= sum && sum <= k){
          ans++;
        }
      }
    }
    System.out.println(ans);

    sc.close();
  }
}
