import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    int a[] =new int[m];
    int b[] =new int[m];
    boolean st[] = new boolean[200000];
    boolean en[] = new boolean[200000];
    boolean ju = false;
    int stn = 0;
    int enn = 0;
    
    for(int i = 0 ; i < m ; ++i){
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
      if(a[i]==1){
        st[b[i]] = true;
      }
      if(b[i]==n){
        en[a[i]] = true;
      }
    }

    for(int i = 0 ; i < 200000 ; ++i){
      if(st[i] && en[i]){
        ju = true;
        break;
      }

    }
    
    if(ju) System.out.println("POSSIBLE");
    else System.out.println("IMPOSSIBLE");

  }
}
