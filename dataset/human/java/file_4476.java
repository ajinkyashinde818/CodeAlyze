import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    
    int ans = 0;
    ans += B;
    if(C-B >= 0){
      ans += B;
      C -= B;
    }else{
      ans += C;
      C = 0;
    }
    
    if(C-A >= 1){
      ans += (A+1);
    }else if(C-A == 0){
      ans += A;
    }else{
      ans += C;
    }
    System.out.println(ans);
  }
}
