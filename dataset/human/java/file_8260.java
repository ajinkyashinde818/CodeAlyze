import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;
import java.util.Collections;
import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    long a = scan.nextLong();
    long b = scan.nextLong();
    long temp;
    long c = a;
    c *= b;
    while((temp = a%b)!=0) {
      a = b;
      b = temp;
    }
    System.out.println((long)(c/b));
  }
}
