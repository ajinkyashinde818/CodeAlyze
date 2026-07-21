import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int number, i, sum = 0, tmp = -1;
    number = Integer.parseInt(sc.next());
    int[] order = new int[number];
    int[] score = new int[number];
    int[] additional = new int[number-1];
    for(i = 0; i < number; i++) {
      order[i] = Integer.parseInt(sc.next());
    }
    for(i = 0; i < number; i++) {
      score[i] = Integer.parseInt(sc.next());
    }
    for(i = 0; i < number-1; i++) {
      additional[i] = Integer.parseInt(sc.next());
    }
    for(i = 0; i < number; i++) {
      sum += score[order[i] - 1];
      if(tmp + 1 == order[i]) sum += additional[tmp - 1];
      tmp = order[i];
    }
    System.out.println(sum);
  }
}
