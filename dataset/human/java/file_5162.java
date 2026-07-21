import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
      String S = sc.next();
      int Q = sc.nextInt();
      ArrayList<String> bf = new ArrayList<>();
      ArrayList<String> af = new ArrayList<>();
      boolean asc =true;
      int Ti;
      int Fi;
      String Ci;
	for(int i=0;i<Q;i++){
      Ti = sc.nextInt();
      if(Ti==1){
        asc = !asc;
        continue;
      }
      Fi = sc.nextInt();
      if(asc){
        if(Fi==1){
          bf.add(sc.next());
        }else{
          af.add(sc.next());
        }
      }else{
        if(Fi==2){
          bf.add(sc.next());
        }else{
          af.add(sc.next());
        }
      }
    }
      String str ="";
if(asc){
  Collections.reverse(bf);
    str+=String.join("", bf);
  str+=S;
    str+=String.join("", af);
}else{
    Collections.reverse(af);
  str+=String.join("", af);
  String[] st = S.split("");
  List<String> sta = Arrays.asList(st);
  Collections.reverse(sta);
  str+=String.join("", sta);
  str+=String.join("", bf);
}
      System.out.println(str);


    }
  
  private static long lcm(long m, long n) {
    return m * n / gcd(m, n);
}
  
  private static long gcd(long m, long n) {
    if(m < n) return gcd(n, m);
    if(n == 0) return m;
    return gcd(n, m % n);
}
}
