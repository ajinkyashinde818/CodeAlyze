import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
	
	int k = sc.nextInt();
    int n = sc.nextInt();
    int[] a = new int[n];
    int[] x = new int[n];
    for(int i = 0; i<n; i++){
      a[i] = sc.nextInt();
    }
    
    x[0] = a[0]+k-a[n-1];
    int max = 0;
    for(int i=1; i<n; i++){
      x[i] = a[i]-a[i-1];
      if(x[max] < x[i]){
        max = i;
      }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
      if(max!=i){
        ans += x[i];
      }
    }
    
    System.out.println(ans);
  }
}
