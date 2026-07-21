import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    int[] b = new int[n];
    int[] r = new int[n + 1];
    for(int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
      r[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
      b[i] = sc.nextInt();
      r[b[i]]++;
    }

    int p = 0;
    for(int i = 1; i <= n; i++) {
      if(r[i] > n) p++;
    }
    if(p > 0) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
      int[] c = new int[n];
      for(int i = n - 1; i >= 0; i--) {
        c[n - 1 - i] = b[i];
      }
      int q = 0;
      int x = 0;
      int t1 = n;
      int t2 = 0;
      for(int i = 0; i < n; i++) {
        if(a[i] == c[i]) {
          q++;
          x = a[i];
          t1 = Math.min(t1, i);
          t2 = Math.max(t2, i);
        }
      }
      if(q == 0) {
        for(int i = 0; i < n; i++) {
          System.out.print(c[i] + " ");
        }
      } else {
        int s11 = -1;
        int s12 = n;
        int s21 = -1;
        int s22 = n;
        
        for(int i = 0; i < n; i++) {
          if((a[i] != x) && (i < t1)) s11 = i;
          if((a[i] != x) && (i > t2)) s12 = Math.min(s12, i);
        }

        for(int i = 0; i < n; i++) {
          if((c[i] != x) && (i < t1)) s21 = i;
          if((c[i] != x) && (i > t2)) s22 = Math.min(s22, i);
        }

        int s = Math.min(s11, s21);
        int t = Math.max(s12, s22);
        
        int k = 0;
        for(int i = t1; i <= t2; i++) {
          int temp = c[i];
          if(k <= s) {
            c[i] = c[k];
            c[k] = temp;
            k++;
          } else if(k < t) {
             k = t;
            c[i] = c[k];
            c[k] = temp;
            k++;
          } else {
            c[i] = c[k];
            c[k] = temp;
            k++;
          }
        }
 
        for(int i = 0; i < n; i++) {
          System.out.print(c[i] + " ");
        }
      }
    }
  }
}
