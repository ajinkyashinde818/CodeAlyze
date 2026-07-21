import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    String a[] = new String[n];
    String b[] = new String[m];
    boolean ju = false;
    for(int i = 0 ; i < n ; ++i){
      a[i] = sc.next();
    }
    for(int i = 0 ; i < m ; ++i){
      b[i] = sc.next();
    }
    
    for(int i = 0; i <= n-m; i++){
      for(int j = 0; j <= n-m; j++){
        int count = 0;
        for(int k = 0; k < m; k++){
          if(b[k].equals(a[i+k].substring(j,j+m))){
            count++;
          }
        }
        if(count == m){
          ju = true;
          break;
        }
      }
      if(ju) break;
    }
    
    if(ju) System.out.println("Yes");
    else System.out.println("No");
    
  }
}
