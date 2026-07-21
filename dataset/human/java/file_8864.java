import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int a = A;
    int b = B;
    int max = A;
    int count = 0;
    if(A<B)max=B;
    for(int i = max;i > 0;i--){
      if(A%i==0&&B%i==0)count++;
      if(count == C){
        a = i;  
        break;
      }
    }
    System.out.println(a);
  }
}
