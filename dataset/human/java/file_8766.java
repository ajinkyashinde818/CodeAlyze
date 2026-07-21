import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();
    int cnt = 0;
    for(int i = Math.max(A,B); i>=1; i--){
      if(A%i == 0 && B%i==0){
        cnt++;
        if(cnt == K){
          System.out.println(i);
          break;
        }
      }
    }
  }
}
