import java.util.Scanner;
import java.util.ArrayList;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    ArrayList <Integer> li = new ArrayList <Integer>();
    ArrayList <Integer> lili = new ArrayList <Integer>();
    for(int i=0;i<n;i++){
      int a = sc.nextInt();
      li.add(a);
      lili.add(0);
    }
    for(int i=0;i<n-1;i++){
      lili.set(i,li.get(i+1)-li.get(i));
    }
    lili.set(n-1,k-li.get(n-1)+li.get(0));
    int b = lili.get(0);
    for(int i=1;i<n;i++){
      int a = Math.max(b,lili.get(i));
      b = a;
    }
    System.out.println(k-b);
  }
}
