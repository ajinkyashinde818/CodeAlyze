import java.util.*;

class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    String x = sc.next();
    String y = sc.next();
    String a[] = x.split("");
    String b[] = y.split("");

    Arrays.sort(a);
    Arrays.sort(b, Comparator.reverseOrder());

    String as = String.join("", a);
    String bs = String.join("", b);

    //System.out.println(as);
    //System.out.println(bs);

    if (as.compareTo(bs) < 0){
      System.out.println("Yes");
    }
    else{
      System.out.println("No");
    }
  }
}
