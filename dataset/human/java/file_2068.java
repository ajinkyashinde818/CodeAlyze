import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int answer = 0;
    long n = sc.nextLong();
    long div = 2;
    long limit = (long)Math.sqrt(n) + 1;
    while(div <= limit){
      int divCnt = 0;
      while(n % div == 0){
        divCnt++;
        n /= div;
      }
      answer += countNumber(divCnt);
      if(div == 2){
        div++;
      } else {
        div += 2;
      }
    }
    if(n != 1){
      answer++;
    }
    System.out.println(answer);
  }
  static int countNumber(int n){
    int ret = 0;
    int counter = 1;
    while(counter <= n){
      n -= counter;
      ret++;
      counter++;
    }
    return ret;
  }
}
