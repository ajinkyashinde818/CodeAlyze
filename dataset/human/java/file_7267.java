import java.util.Scanner;

public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] a = new int[n];
    int[] b = new int[n + 1];
    int sum = 0;
    for(int i = 0;i < n;i++){
      a[i] = sc.nextInt();
      if(i == 0){
        b[i] = a[i];
      }else{
        b[i] = a[i] - a[i - 1];
      }
      b[n] = k - a[n - 1];
    }
    int last = b[0] + b[n];
    int max = last;
    for(int j = 1;j < n;j++){
      max = Math.max(max , b[j]);
    }  
    int ans = k - max;
    System.out.println(ans);
  }
}
