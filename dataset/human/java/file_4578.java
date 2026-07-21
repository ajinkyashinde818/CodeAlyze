import java.util.Scanner;
public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    final int A,B,C;
    int ans=0;
    A = sc.nextInt();B=sc.nextInt();C=sc.nextInt();
    if(A+B >= C){
      ans = B+C;
    }
    else{
      if(A >= B ){
        ans = A + B +Math.min(C-A,B)+1;
      }
      else {
        ans =A + B + Math.min(C-A,B)+1;
      }
    }
    System.out.println(ans);
  }
}
