import java.util.*;
class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    int next[]=new int[n];
    boolean flg[]=new boolean[n];
    for(int i=0;i<n;i++){
      next[i]=sc.nextInt()-1;
    }
    int now = 0;
    while(!flg[now]&&k>0){
      flg[now]=true;
      now = next[now];
      k--;
    }
    if(k!=0){
      ArrayList<Integer> list = new ArrayList<Integer>();
      int moto = now;
      list.add(now); now = next[now];
      while(now!=moto){
        list.add(now);
        now = next[now];
      }
      k = k%list.size();
      now = moto;
      for(long i=0;i<k;i++){
        now = next[now];
      }
    }
    now++;
    pl(now+"");

  }
  public static void pr(String str){
    System.out.print(str);
  }
  public static void pl(String str){
    System.out.println(str);
  }
}
