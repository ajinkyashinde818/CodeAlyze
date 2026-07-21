import java.util.*;
 
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong(); 
    long B = sc.nextLong();
    long a = A;
    long b = B;
    long r = 1;
    for (;r!=0;){
      r = a % b;
      a = b;
      b = r;
    }
    long ans = A * B / a;
    System.out.println(ans);
  }
}
