import java.io.InputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;

public class Main{

static PrintWriter out;
static InputReader ir;

static void solve(){
 int n=ir.nextInt();
 while(n-->0){
  int tot=0;
  for(int i=0;i<2;i++) tot+=MCXItoNumber(ir.next());
  out.println(NumbertoMCXI(tot));
 }
}

public static int MCXItoNumber(String s){
 int[] dig=new int[4];
 Arrays.fill(dig,-1);
 int v=-1;
 for(int i=s.length()-1;i>=0;i--){
  char c=s.charAt(i);
  int td=td(c);
  if(td==-1) dig[v]=c-'0';
  else{
   if(v!=-1&&dig[v]==-1) dig[v]=1;
   v=td;
  }
 }
 if(v!=-1&&dig[v]==-1) dig[v]=1;
 for(int i=0;i<4;i++) if(dig[i]<0) dig[i]=0;
 int ret=0;
 for(int i=0;i<4;i++){
  ret+=Math.pow(10,i)*dig[i];
 }
 return ret;
}

public static String NumbertoMCXI(int a){
 int[] dig=new int[4];
 for(int i=3;i>=0;i--){
  dig[i]=(int)(a/Math.pow(10,i));
  a-=dig[i]*Math.pow(10,i);
 }
 String ret="";
 for(int i=3;i>=0;i--){
  if(dig[i]==0) continue;
  else if(dig[i]!=1) ret+=Integer.toString(dig[i]);
  ret+=tc(i);
 }
 return ret;
}

public static int td(char s){
 if(s=='m') return 3;
 else if(s=='c') return 2;
 else if(s=='x') return 1;
 else if(s=='i') return 0;
 else return -1;
}

public static String tc(int s){
 if(s==3) return "m";
 else if(s==2) return "c";
 else if(s==1) return "x";
 else return "i";
}

public static void main(String[] args) throws Exception{
 ir=new InputReader(System.in);
 out=new PrintWriter(System.out);
 solve();
 out.flush();
}

static class InputReader {
 private InputStream in;
 private byte[] buffer=new byte[1024];
 private int curbuf;
 private int lenbuf;

 public InputReader(InputStream in) {this.in=in; this.curbuf=this.lenbuf=0;}
 
 public boolean hasNextByte() {
  if(curbuf>=lenbuf){
   curbuf= 0;
   try{
    lenbuf=in.read(buffer);
   }catch(IOException e) {
    throw new InputMismatchException();
   }
   if(lenbuf<=0) return false;
  }
  return true;
 }

 private int readByte(){if(hasNextByte()) return buffer[curbuf++]; else return -1;}
 
 private boolean isSpaceChar(int c){return !(c>=33&&c<=126);}
 
 private void skip(){while(hasNextByte()&&isSpaceChar(buffer[curbuf])) curbuf++;}
 
 public boolean hasNext(){skip(); return hasNextByte();}
 
 public String next(){
  if(!hasNext()) throw new NoSuchElementException();
  StringBuilder sb=new StringBuilder();
  int b=readByte();
  while(!isSpaceChar(b)){
   sb.appendCodePoint(b);
   b=readByte();
  }
  return sb.toString();
 }
 
 public int nextInt() {
  if(!hasNext()) throw new NoSuchElementException();
  int c=readByte();
  while (isSpaceChar(c)) c=readByte();
  boolean minus=false;
  if (c=='-') {
   minus=true;
   c=readByte();
  }
  int res=0;
  do{
   if(c<'0'||c>'9') throw new InputMismatchException();
   res=res*10+c-'0';
   c=readByte();
  }while(!isSpaceChar(c));
  return (minus)?-res:res;
 }
 
 public long nextLong() {
  if(!hasNext()) throw new NoSuchElementException();
  int c=readByte();
  while (isSpaceChar(c)) c=readByte();
  boolean minus=false;
  if (c=='-') {
   minus=true;
   c=readByte();
  }
  long res = 0;
  do{
   if(c<'0'||c>'9') throw new InputMismatchException();
   res=res*10+c-'0';
   c=readByte();
  }while(!isSpaceChar(c));
  return (minus)?-res:res;
 }

 public double nextDouble(){return Double.parseDouble(next());}

 public int[] nextIntArray(int n){
  int[] a=new int[n];
  for(int i=0;i<n;i++) a[i]=nextInt();
  return a;
 }

 public long[] nextLongArray(int n){
  long[] a=new long[n];
  for(int i=0;i<n;i++) a[i]=nextLong();
  return a;
 }

 public char[][] nextCharMap(int n,int m){
  char[][] map=new char[n][m];
  for(int i=0;i<n;i++) map[i]=next().toCharArray();
  return map;
 }
}
}
