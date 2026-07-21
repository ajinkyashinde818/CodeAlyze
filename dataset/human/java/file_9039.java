import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    int m = Integer.parseInt(sc.next());
    int x[] = new int[m];
    long s[] = new long[n];
    int ng[] = new int[n];
    int ans = 0;
    int t = 0;
    
    for (int i=0; i<m; i++){
      x[i] = Integer.parseInt(sc.next());
    }
    
    int j = 0;
    for(int i=0; i<n; i++){
      ng[i] = 0;
      if(m > 0 &&i == x[j]-1){
        ng[i] = 1;
        if(j != m-1){ 
          j++;
        }
      }
    }
    
    if(n==1){
      System.out.println("1");
      return;
    }
    
    if(n==2){
      if(m==1){
        System.out.println("1");
        return;
      } else {
      	System.out.println("2");
        return;
      }
    }
    
    if(ng[0]==1){
	  s[0] = 0;
      if(ng[1] == 1) {
        s[1] = 0;
      } else {
        s[1] = 1;
      }
    } else {
      s[0] = 1;
      if(ng[1] == 1){
        s[1] = 0;
      } else {
        s[1] = 2;
      }
    }
    
    for(int i=2; i<n; i++){
      if(ng[i] == 0){
        s[i] = (s[i-1]%1000000007 + s[i-2]%1000000007)%1000000007;
      } else {
        s[i] = 0;
      }
    }
    
    System.out.println(s[n-1]%1000000007);
  }
}
