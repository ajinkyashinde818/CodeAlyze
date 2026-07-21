import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    int m = scan.nextInt();
    int sum = 0;
    if (n>=m){
      sum = m;
    }
    else{
      sum = n;
    }
    int what = -1;
    for (int i=sum;i>1;i--){
      if ((n%i == 0) && (m%i == 0)){
        what = i;
        break;
      }
    }

    if (what == -1){
      what = 1;
    }


    long g = (long) n*m/what;
    System.out.println(g);
  }
}
