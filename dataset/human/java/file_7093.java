import java.util.Scanner;
import java.util.ArrayList;

public class Main {
  public static void main(String[] args) {
    Scanner scnr = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<Integer>();
    
    int len = scnr.nextInt();
    int numHouse = scnr.nextInt();
    for (int i = 0; i < numHouse; i++) {
      list.add(scnr.nextInt());
    }
    
    int betweenLen = 0;
    int maxBetweenLen = list.get(0);
    
    for (int i = 0; i < list.size(); i++) {
      if (i == list.size() - 1) {
        betweenLen = len - list.get(i) + list.get(0);
      }
      else {
        betweenLen = list.get(i + 1) - list.get(i);
      }
      
      // System.out.println(betweenLen);
      
      if (maxBetweenLen < betweenLen) {
        maxBetweenLen = betweenLen;
      }
    }
    
    // System.out.println(len);
    // System.out.println(numHouse);
    // System.out.println(list);
    System.out.println(len - maxBetweenLen);
  }
}
