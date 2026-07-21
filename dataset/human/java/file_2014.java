import java.util.*;
import java.io.*;
class Main{
  public static void main(String args[]){
    long a = readLong();
    ArrayList<Long> beki = new ArrayList<Long>();
    boolean flg = true;
    for(long i=2;a>1;){
      if(a%i==0){
        a/=i;
        if(flg){
          beki.add(1L);
          flg = false;
        }else{
          beki.set(beki.size()-1,beki.get(beki.size()-1)+1);
        }
      }else{
        flg = true;
        if(i*i>a){
          beki.add(1L);
          break;
        }
        i++;
      }
    }
    long count=0;
    for(int i=0;i<beki.size();i++){
      long e = 1;
      long z = beki.get(i);
      while(z>=e){
        count++;
        z-=e;
        e++;
      }
    }
    pl(count+"");
  }
  static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void pr(String str){
    System.out.print(str);
  }
  public static void pl(String str){
    System.out.println(str);
  }
  public static String readL(){
    try{
      return br.readLine();
    }catch(IOException e){
      e.printStackTrace();
      return "";
    }
  }
  public static String readS(){
    StringBuilder sb = new StringBuilder();
    while(true){
      try{
        int k = br.read();
        if(k==-1||(char)k==' '||(char)k=='\n'){break;}
        sb.append((char)k);
      }catch(IOException e){
        e.printStackTrace();
      }
    }
    return sb.toString();
  }
  public static int readI(){
    return stoi(readS());
  }
  public static long readLong(){
    return Long.parseLong(readS());
  }
  public static String[] readSs(){
    return readL().split(" ");
  }
  public static int[] readIs(){
    return stoi(readSs());
  }
  public static int stoi(String s){
    return Integer.parseInt(s);
  }
  public static int[] stoi(String s[]){
    int a[]=new int[s.length];
    for(int i=0;i<s.length;i++){
      a[i]=stoi(s[i]);
    }
    return a;
  }
  public static String itos(int i){
    return String.valueOf(i);
  }
  public static String[] itos(int[] a){
    String s[]=new String[a.length];
    for(int i=0;i<a.length;i++){
      s[i]=itos(a[i]);
    }
    return s;
  }
  public static String ctos(char c){
    return String.valueOf(c);
  }
  public static String cstos(char[] c){
    return new String(c);
  }
  public static char stoc(String s){
    return s.charAt(0);
  }
  public static char[] stocs(String s){
    return s.toCharArray();
  }
}
