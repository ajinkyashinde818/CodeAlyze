import java.util.Scanner;
class Main {
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int k = scanner.nextInt();
    int n = scanner.nextInt();
    int[] a = new int[n];
    for(int i = 0;i < n;i++){
      a[i] = scanner.nextInt();
    }
    int difference = 0;
    for(int i = 0;i < n - 1;i++){
      if(a[i+1] - a[i] > difference)difference = a[i+1] - a[i];
    }
    if(a[0] - a[n-1] + k > difference)difference = a[0] - a[n-1] + k;
    System.out.println(k - difference);
  }
}
