import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);    
    int circle = scan.nextInt();
    int num = scan.nextInt();
    
    List<Integer> length = new ArrayList<>();
    for(int i = 0; i < num; i++) {
      length.add(scan.nextInt());
    }
    scan.close();

    List<Integer> diff = new ArrayList<>();
    
    for(int i = 0; i < length.size() - 1; i++) {
      diff.add(length.get(i + 1) - length.get(i));
    }
      diff.add(circle - length.get(length.size() - 1) + length.get(0));
    
    Collections.sort(diff, Collections.reverseOrder());
    
    System.out.println(circle - diff.get(0));
    
  }
}
