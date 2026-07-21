import java.util.*;
import static java.lang.System.*;

class Main {
  public static final int MOD = 1000000007;
  public static final int INF = 1000000000;
  public static void main(String[] args) {
    Scanner sc = new Scanner(in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    List<Integer> A = new ArrayList<Integer>();
    List<Integer> B = new ArrayList<Integer>();
    for(int i=0; i<M; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      if(a == 1) B.add(b);
      if(b == N) A.add(a);
    }
    Collections.sort(A);
    Collections.sort(B);
    int j = 0;
    int k = 0;
    boolean check = false;
    for(int i=1; i<=N; i++){
      while(j < A.size() && A.get(j) < i) j++;
      while(k < B.size() && B.get(k) < i) k++;
      if(j >= A.size() || k >= B.size()) break;
      if(A.get(j).equals(B.get(k)) ){
        check = true;
        break;
      }
    }
    if(check == true) out.println("POSSIBLE");
    else out.println("IMPOSSIBLE");   
  }

  public static int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
  }
}
