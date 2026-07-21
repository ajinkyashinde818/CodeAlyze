import java.util.Scanner;

public class Main{
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int K = s.nextInt();
    int S = s.nextInt();
    int Ans = 0;
    if (S <= K)
      Ans = (S+1) * (S+2) / 2;
    else if (K < S && S <= 2*K)
      Ans = (K+1)*(K+1) - (2*K - S +1)*(2*K - S)/2 - (S -K +1)*(S-K)/2;
    else if (2*K <= S)
      Ans = (3*K -S +1)*(3*K - S +2)/2;
    System.out.println(Ans);
  }
}
