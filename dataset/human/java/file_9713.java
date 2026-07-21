import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.TreeSet;
 
public class Main {
  public static void main(String[] args) {
    InputReader sc = new InputReader(System.in);
 
    int n = sc.nextInt();
    int[] parentlist = new int[n];
    int[] siblinglist = new int[n];
    int[] degreelist = new int[n];
    int[] depthlist = new int[n];
    int[] heightlist = new int[n];
    int[] leftlist = new int[n];
    int[] rightlist = new int[n];
    boolean[] rootcheck = new boolean[n];
    boolean[] leafcheck = new boolean[n];
    for(int i = 0; i < n; i++){
      rootcheck[i] = true;
      leafcheck[i] = false;
    }
    for(int i = 0; i < n; i++){
      int id = sc.nextInt();
      int left = sc.nextInt();
      int right = sc.nextInt();
      if(left < 0 && right < 0){
        leafcheck[id] = true;
        degreelist[id] = 0;
      }else if(left >= 0 && right >= 0){
        degreelist[id] = 2;
        siblinglist[left] = right;
        siblinglist[right] = left;
        parentlist[left] = id;
        parentlist[right] = id;
        rootcheck[left] = false;
        rootcheck[right] = false;
        leftlist[id] = left;
        rightlist[id] = right;
      }else if(left >= 0){
        degreelist[id] = 1;
        siblinglist[left] = -1;
        parentlist[left] = id;
        rootcheck[left] = false;
        leftlist[id] = left;
        rightlist[id] = -1;
      }else{
        degreelist[id] = 1;
        siblinglist[right] = -1;
        parentlist[right] = id;
        rootcheck[right] = false;
        rightlist[id] = right;
        leftlist[id] = -1;
      }
    }

    int rootind = -1;
    for(int i = 0; i < n; i++){
      if(rootcheck[i]){
        rootind = i;
        break;
      }
    }
    parentlist[rootind] = -1;
    siblinglist[rootind] = -1;

    LinkedList<Integer> indexqueue = new LinkedList<Integer>();
    LinkedList<Integer> depthqueue = new LinkedList<Integer>();
    indexqueue.add(rootind);
    depthqueue.add(0);
    depthlist[rootind] = 0;

    while(!indexqueue.isEmpty()){
      int nowindex = indexqueue.poll();
      int nowdepth = depthqueue.poll();
      if(degreelist[nowindex] == 0){continue;}
      if(leftlist[nowindex] >= 0){
        depthlist[leftlist[nowindex]] = nowdepth + 1;
        indexqueue.add(leftlist[nowindex]);
        depthqueue.add(nowdepth+1);        
      }
      if(rightlist[nowindex] >= 0){
        depthlist[rightlist[nowindex]] = nowdepth + 1;
        indexqueue.add(rightlist[nowindex]);
        depthqueue.add(nowdepth+1);
      }
    }


    for(int i = 0; i < n; i++){
      heightlist[i] = 0;
    }
    indexqueue.clear();
    LinkedList<Integer> heightqueue = new LinkedList<Integer>();
    for(int i = 0; i < n; i++){
      if(leafcheck[i]){
        indexqueue.add(i);
        heightqueue.add(0);
      }
    }
    while(!heightqueue.isEmpty()){
      int nowindex = indexqueue.poll();
      int nowheight = heightqueue.poll();
      if(parentlist[nowindex] < 0){
        continue;
      }
      if(heightlist[parentlist[nowindex]] < nowheight + 1){
        heightlist[parentlist[nowindex]] = nowheight + 1;
        indexqueue.add(parentlist[nowindex]);
        heightqueue.add(nowheight + 1);
      }
    }

    for(int i = 0; i < n; i++){
      System.out.print("node ");
      System.out.print(i);
      System.out.print(": parent = ");
      System.out.print(parentlist[i]);
      System.out.print(", sibling = ");
      System.out.print(siblinglist[i]);
      System.out.print(", degree = ");
      System.out.print(degreelist[i]);
      System.out.print(", depth = ");
      System.out.print(depthlist[i]);
      System.out.print(", height = ");
      System.out.print(heightlist[i]);
      if(rootcheck[i]){
        System.out.println(", root");
      }else if(leafcheck[i]){
        System.out.println(", leaf");
      }else{
        System.out.println(", internal node");
      }
    }
  }
 
//nextChar を追加したよ！
  
// LinkedList<Integer>[] setsu = new LinkedList[n];
// for(int i = 0; i < n; i++){
//   setsu[i] = new LinkedList<Integer>();
// } 

 //ここからテンプレ
  static class InputReader {
      private InputStream stream;
      private byte[] buf = new byte[1024];
      private int curChar;
      private int numChars;
      private SpaceCharFilter filter;

      public InputReader(InputStream stream) {
          this.stream = stream;
      }
 
      public int next() {
          if (numChars == -1)
              throw new InputMismatchException();
          if (curChar >= numChars) {
              curChar = 0;
              try {
                  numChars = stream.read(buf);
              } catch (IOException e) {
                  throw new InputMismatchException();
              }
              if (numChars <= 0)
                  return -1;
          }
          return buf[curChar++];
      }
 
      public String nextStr() {
        int c = next();
        while(isSpaceChar(c)){c = next();}
        StringBuffer str = new StringBuffer();
        do{
          str.append((char)c);
          c = next();
        }while(!isSpaceChar(c));
        return str.toString();
      }

      public char nextChar() {
        int c = next();
        while(isSpaceChar(c)){c = next();}
        char ret;
        do{
          ret = (char)c;
          c = next();
        }while(!isSpaceChar(c));
        return ret;
      }

      public int nextInt() {
          int c = next();
          while (isSpaceChar(c))
              c = next();
          int sgn = 1;
          if (c == '-') {
              sgn = -1;
              c = next();
          }
          int res = 0;
          do {
              if (c < '0' || c > '9')
                  throw new InputMismatchException();
              res *= 10;
              res += c - '0';
              c = next();
          } while (!isSpaceChar(c));
          return res * sgn;
      }
 
      public boolean isSpaceChar(int c) {
          if (filter != null)
              return filter.isSpaceChar(c);
          return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
      }
 
      public interface SpaceCharFilter {
          public boolean isSpaceChar(int ch);
      }
  }
}
