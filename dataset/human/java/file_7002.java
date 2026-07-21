import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
	int k = sc.nextInt();
    int n = sc.nextInt();
    int alist[] = new int[n];
    for(int i = 0; i < n; i++){
      alist[i] = sc.nextInt();
    }
    
    int distMax = 0;
    
    for(int i = 0; i < n-1; i++){
      distMax = Math.max(alist[i+1]-alist[i], distMax);
    }
    distMax = Math.max(alist[0]-(alist[n-1]-k), distMax);
    System.out.println(k - distMax);
  }
}
