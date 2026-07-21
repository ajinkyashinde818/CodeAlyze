import java.util.Scanner;

public class Main { 
  public static void main(String[] args) {

    int count = 0;
    int max = 0;
    int D1 = 0;
    int D2 = 0; 

    Scanner scanner = new Scanner(System.in);
    int N = Integer.parseInt(scanner.next());
    for (int i = 0; i < N; i++){
      D1 = Integer.parseInt(scanner.next());
      D2 = Integer.parseInt(scanner.next());
      if (D1 == D2) {
        count++;
        if (count == N){
          max = count;
        }
      } else {
        if (count > max){
          max = count;
        }
        count = 0;
      }
    }
    scanner.close();

    if (max >= 3){
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
