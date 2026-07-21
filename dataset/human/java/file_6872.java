import java.util.*;

class Main {
  public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
    
    long K = sc.nextLong();//next(文字列), nextDouble, nextLine(1行)とか
    int N = sc.nextInt();
    long[] S = new long[N];
    for (int i = 0; i < N;i++){
      S[i] = sc.nextLong();
    }
    long sum = 0;
    long max =0;
    for (int i = 0; i<N-1;i++){
      sum += S[i+1] - S[i];
      max = Math.max(max,(S[i+1]-S[i]));
    }
    sum += K-S[N-1]+S[0];
    max = Math.max(max,K-S[N-1]+S[0]);
    sum -= max;
    System.out.println(sum);      
  }    
}
