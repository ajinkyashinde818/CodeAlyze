import java.io.*;
import java.util.*;
 
public class Main {
public static void main(String[] args) throws IOException {
  Scanner sc = new Scanner(System.in);
  PrintWriter pw = new PrintWriter(System.out);
  
  int dishes = sc.nextInt();
  int[] dishOrder = new int[dishes];
  int[] bSat = new int[dishes];
  int[] cSat = new int[dishes-1];
  for (int i = 0; i < dishes; i++) {
    dishOrder[i] = sc.nextInt();
  }
  for (int i = 0; i < dishes; i++) {
    bSat[i] = sc.nextInt();
  }
  for (int i = 0; i < dishes-1; i++) {
    cSat[i] = sc.nextInt();
  }
  int count = 0;
  count += bSat[dishOrder[0]-1];
  for (int i = 1; i < dishes; i++) {
    count += bSat[dishOrder[i]-1];
    if (dishOrder[i-1] + 1 == dishOrder[i]) {
      count += cSat[dishOrder[i-1]-1];
    }
  }
  pw.println(count);
  
  sc.close();
  pw.close();
}
}
