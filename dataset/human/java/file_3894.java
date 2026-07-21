import java.util.*;

class Main{
  static int repow(int b,int p){
    System.err.println(b+"^"+p);
    int res=1;
    int a=b;
    while(p>0){
      if((p&1)==1){
        res*=a;
      }
      a*=a;
      p/=2;
    }
    System.err.println("="+res);
    return res;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s=sc.next();
    int cnt=0;
    int fr=0;
    int ba=s.length()-1;
    while(fr<ba){
      if(s.charAt(fr)==s.charAt(ba)){
        fr++;
        ba--;
      }else{
        if(s.charAt(fr)=='x'){
          fr++;
          cnt++;
        }else if(s.charAt(ba)=='x'){
          ba--;
          cnt++;
        }else{
          System.out.println(-1);
          return;
        }
      }
    }
    System.out.println(cnt);
  }
}
