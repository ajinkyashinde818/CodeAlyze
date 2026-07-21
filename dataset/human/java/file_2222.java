import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);

    long n = scan.nextLong();
    int g = (int) Math.sqrt(n);
    ArrayList<Long> a = new ArrayList<Long>();
    for (int i=g;i>=1;i--){
      if (n%i == 0){
        long a1 = (long) i;
        long a2 = (long) n/i;
        if (check(a1) == true){
          a.add(a1);
        }
        if (check(a2) == true){
          a.add(a2);
        }
      }
    }

    long sum = 0;
    for(long k : a){
      long check = n;
      int count = 0;
      while (check % k == 0){
        count += 1;
        check = (long) check/k;
      }
      sum += find(count);
    }
    System.out.println(sum);
  }

  static boolean check(long a){
    if (a == 1){
      return false;
    }

    int b = (int) Math.sqrt(a);
    for (int i=b;i>=2;i--){
      if (a%i == 0){
        return false;
      }
    }
    return true;
  }

  static int find(int a){
    int count = 0;
    while (((count*count+count)/2) <= a){
      count += 1;
    }
    return count-1;
  }

}
