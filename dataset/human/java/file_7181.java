import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int k = scan.nextInt();
    int n = scan.nextInt();
    int g = 0;
    ArrayList<Integer> c = new ArrayList<Integer>();
    for (int i=0;i<n;i++){
      g = scan.nextInt();
      c.add(g);
    }

    ArrayList<Integer> a = new ArrayList<Integer>();
    ArrayList<Integer> b = new ArrayList<Integer>();

    for (int j=0;j<n;j++){
      if (j == 0){
        a.add(c.get(n-1) - c.get(0));
        b.add(k - c.get(1) + c.get(0));
        continue;
      }
      if (j == n-1){
        a.add(k-c.get(n-1)+c.get(n-2));
        b.add(c.get(n-1) - c.get(0));
        continue;
      }
      a.add(k-c.get(j)+c.get(j-1));
      b.add(k-c.get(j+1)+c.get(j));
    }

    int min = k;
    for (int t = 0;t<n;t++){
      if (a.get(t) < min){
        min = a.get(t);
      }
      if (b.get(t) < min){
        min = b.get(t);
      }
    }
    System.out.println(min);
  }
}
