import java.util.Arrays;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k =  sc.nextInt();
    int n =  sc.nextInt();
    int a[] = new int[n];
    int dis[] = new int[n];

    for(int i=0;i<n;i++) {
    	a[i] = sc.nextInt();
    }

    for(int j=0;j<n-1;j++) {
    	dis[j] = a[j+1]-a[j];
    }
    dis[n-1] = k+a[0] - a[n-1];
    Arrays.sort(dis);
    System.out.println(k-dis[n-1]);
  }
}
