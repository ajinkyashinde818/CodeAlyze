import java.util.Scanner;

public class Main{
  static int gcd(int a ,int b){return b>0? gcd(b,a%b):a;}
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int count = 0;
    int max_gcd = gcd(a,b);
    int ans=0;

    for(int i= max_gcd; i>0; i--){
      if(a%i==0 && b%i==0){
        count += 1;
      }
      if(count == k){
        ans = i;
        break;
      }
    }
    System.out.println(ans);

  }
}
