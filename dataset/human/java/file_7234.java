import java.util.Scanner;
class Main {
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] a = new int[n + 1];
    int i;
    for(i = 0; i<n; i++){
      a[i] = sc.nextInt();
    }
    a[n] = k;
    int max = a[n] - a[n-1] + a[0];
    for(i = 0 ; i < n ; i++){
      max = Math.max(max , a[i + 1] - a[i]);
    }


    System.out.println(k - max);

  }
}
