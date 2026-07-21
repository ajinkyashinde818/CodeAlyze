import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

  static int mod = 1000000007;

  public static void main(String[] args) throws FileNotFoundException {

//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);

    int n = cin.nextInt();

    long[] num = new long[n];
    int count = 0;
    long sum = 0;
    for (int i=0;i<n;i++) {
      long item = cin.nextLong();
      if (item<0)
        count++;
      num[i] = Math.abs(item);
      sum += Math.abs(item);
    }
    if (count%2==0) {
      System.out.println(sum);
    }
    else {
      Arrays.sort(num);
      sum -= 2*num[0];
      System.out.println(sum);
    }

  }


}
