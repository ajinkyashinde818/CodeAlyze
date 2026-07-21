import java.util.*;

class Main{
  static int gcd(int c,int d){
    while(true){
      int f=c%d;
      if(f==0){
        return d;
      }
      c=d;
      d=f;
    }
  }
  static ArrayList<Integer> divList(int n){
    ArrayList<Integer> div=new ArrayList<Integer>();
    for(int i=1;i*i<=n;i++){
      if(n%i==0){
        div.add(i);
        if(i*i!=n){
          div.add((int)(n/i));
        }
      }
    }
    return div;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a=sc.nextInt();
    int b=sc.nextInt();
    int c=gcd(a,b);
    List<Integer> l=divList(c);
    Collections.sort(l);
    System.out.println(l.get(l.size()-sc.nextInt()));
  }
}
