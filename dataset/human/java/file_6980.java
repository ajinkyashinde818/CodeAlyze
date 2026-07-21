import java.util.Scanner;
 
class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int max = 0;
    int d = 0;
    int first = sc.nextInt();
    int prev = first;
    int next = 0;
    for(int i = 0; i < n-1; i++){
      next = sc.nextInt();
      d = next - prev;
      if(max < d){
        max = d;
      }
      prev = next;
    }
    int b = k - next + first;
    if(max < b){
      max = b;
    }
    System.out.println(k-max);
  }
}
