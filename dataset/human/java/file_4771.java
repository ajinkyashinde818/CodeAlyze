import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String sn = sc.next();
    long n = Long.valueOf(sn);
    int l = sn.length();
    int fi = Integer.valueOf(sn.substring(l-1, l));
    long ans = 0;
    
    if(fi%2 != 0){
      System.out.println(0);
      return;
    }
    
    long nd = n; // - (long)fi;
    long div = 1;
    int c = 0;
    for(int i=1; i<30; i++){
      div *= 5;
      if(nd < div){
        c = i-1;
        break;
      }
    }
    
    div = 1;
    long cans = 1;
    for(int i=1; i<=c; i++){
      div *= 5;
      cans = nd / div / 2;
      ans += cans;
    }
    
    System.out.println(ans);
    
  }
}
