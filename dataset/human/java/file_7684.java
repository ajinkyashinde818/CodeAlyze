import java.util.*;

//update 2020/1/1 23:01

public class Main{

  static Scanner sc = new Scanner(System.in);
  static StringBuilder sb = new StringBuilder();

  public static void main(String[] args) {

    int n = nextInt();
    long k = nextLong();
    int[] a = new int[n];
    for(int i=0;i<n;i++){
      a[i] = nextInt();
    }


    int[] done = new int[n]; //到達回数
    done[0] ++; //初期位置
    int now = 0;
    int cnt = 0;

    boolean flag = false;
    long ccnt = 0;

    int start = 0;

for(int i=0;i<(3*n);i++){ //とりあえず最大3n回テレポート //絶対3回ループする

      //移動回数
      cnt++;

      if(flag){ //フラグ継続中なら
        ccnt ++;
      }

      //移動先を記録
      done[a[now]-1] ++;

      //次の移動先情報を保存
      now = a[now] -1;

      //次の場所一応
      //System.out.println(now+1);

      if(!flag && done[a[now]-1]==2){ //2回目を訪れたのが初めて
        flag = true;
        start = a[now]-1;
      }

      if(flag && done[a[now]-1]==3){ //3回目を訪れたのが初めて
        break;
      }

}


    int ans = 0; //はじめの位置は0

    while(true){
      //今の位置がループの初めなら
      if(ans==start){
        k = k%ccnt; //kを小さく
      }

      if(k==0){
        break;
      }

      //次へ移動
      ans = a[ans]-1;

      //カウンタ
      k--;

      if(k==0){
        break;
      }

    }


    System.out.println((ans+1));

  }











  static int lcm(int a,int b){
    return a*b*gcd(a,b);
  }

  static int gcd(int a,int b){
    if(a%b!=0){
      return gcd(b,a%b);
    }
    else{
      return b;
    }
  }

  /*
    static String toSmall(String s){
      char c = s.charAt(0);
      //if(Character.isUpperCase(c)){
      if(c<=90){
        c += 32;
      }
      return String.valueOf(c);
    }
    static String toBig(String s){
      char c = s.charAt(0);
      //if(Character.isLowerCase(c)){
      if(c>=97){
        c -= 32;
      }
      return String.valueOf(c);
    }
  */

  static String toSmall(String s){
    return s.toLowerCase();
  }

  static String toBig(String s){
    return s.toUpperCase();
  }

  static String next(){
    return sc.next();
  }

  static int nextInt(){
    return Integer.parseInt(sc.next());
  }

  static long nextLong(){
    return Long.parseLong(sc.next());
  }

  static double nextDouble(){
    return Double.parseDouble(sc.next());
  }

  static String[] splitString(String s){
    return s.split("");
  }

  static char[] splitChar(String s){
    return s.toCharArray();
  }

  static int charToInt(char a){
    return a - 48;
  }

////////////////////////////////////////////
  public static int max(int[] a){
    int lng = a.length;
    int max = a[0];
    for(int i=1;i<lng;i++){
      max = Math.max(max,a[i]);
    }
    return max;
  }
  public static long max(long[] a){
    int lng = a.length;
    long max = a[0];
    for(int i=1;i<lng;i++){
      max = Math.max(max,a[i]);
    }
    return max;
  }
////////////////////////////////////////////

////////////////////////////////////////////
  public static int min(int[] a){
    int lng = a.length;
    int min = a[0];
    for(int i=1;i<lng;i++){
      min = Math.min(min,a[i]);
    }
    return min;
  }
  public static long min(long[] a){
    int lng = a.length;
    long min = a[0];
    for(int i=1;i<lng;i++){
      min = Math.min(min,a[i]);
    }
    return min;
  }
////////////////////////////////////////////

}
