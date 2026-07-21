import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    String str_kn = scan.nextLine();
    String str_a = scan.nextLine();
    String[] kn = str_kn.split(" ");
    int k = Integer.parseInt(kn[0]);
    int n = Integer.parseInt(kn[1]);
    String[] str_a_array = str_a.split(" ");
    int[] a = new int[n];
    for(int i=0; i < n; i++){
      a[i] = Integer.parseInt(str_a_array[i]);
    }
    int dst = 0;
    for(int i=0; i < n-1; i++){
      if(dst < a[i+1]-a[i]) dst = a[i+1]-a[i];
    }
    if(dst < k - a[n-1] + a[0]) dst = k - a[n-1] + a[0];
    System.out.println(k-dst);
  }
}
