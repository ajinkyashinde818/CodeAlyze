import java.util.*;

class Main {
  public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);
    
    int N = scanner.nextInt(); //next(文字列), nextDouble, nextLine(1行)とか
	int S = scanner.nextInt();
    
    int ans = 0;
    for (int i = 0; i <= N; i++){
      for (int j = 0; j <= N; j++){
        if (0 <= S - i - j && S - i - j <= N ){
          ans++;
        }
      }
    }
    System.out.println(ans);
  }
}
