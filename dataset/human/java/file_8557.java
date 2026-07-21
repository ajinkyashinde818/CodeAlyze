import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
 
public class Main {
 
  public static void main(String[] args) throws FileNotFoundException {
 
//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);
 
    int a = cin.nextInt();
    int b = cin.nextInt();
    int c = cin.nextInt();
 
    int d = a < b ? a : b;
 
    ArrayList<Integer> factor = new ArrayList<>();
 
    for (int i = 1; i <= d; i++) {
 
      if (a % i == 0 && b % i == 0)
        factor.add(i);
    }
    Collections.sort(factor, Collections.reverseOrder());
    System.out.println(factor.get(c - 1));
  }
 
}
