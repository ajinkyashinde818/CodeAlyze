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
    int[] array1 = new int[n];
    int[] array2 = new int[n];
    for(int i = 0; i < n; i++){
      array1[i] = sc.nextInt();
    }
    for(int i = 0; i < n; i++){
      array2[i] = sc.nextInt();
    }
    int[] ansarray = new int[n];

    boolean noteasy = false;
    int index = 0;
    for(; index < n; index++){
      if(array1[index] == array2[n - index - 1]){
        noteasy = true;
        break;
      }else{
        ansarray[index] = array2[n - index - 1];
      }
    }
    boolean canclear = true;
    int ngnum = 0;
    if(noteasy){
      for(int i = n - 1; i >= index; i--){
        if(array1[i] == array2[i - index]){
          canclear = false;
          ngnum = array1[i];
          break;
        }else{
          ansarray[i] = array2[i - index];
        }
      }
    }

    boolean cancanclear = canclear;
    if(!cancanclear){
      int count1 = 0;
      int count2 = 0;
      for(int i = 0; i < n; i++){
        if(array1[i] == ngnum){count1++;}
        if(array2[i] == ngnum){count2++;}
      }
      if(count1 <= n - count2){cancanclear = true;}
      if(cancanclear){
        int index2 = 0;
        boolean[] usecheck = new boolean[n];
        for(int i = 0; i < n; i++){
          usecheck[i] = false;
        }
        for(int i = 0; i < n; i++){
          if(ngnum == array1[i]){
            while(array2[index2] == ngnum){
              index2++;
            }
            ansarray[i] = array2[index2];
            usecheck[index2] = true;
            index2++;
          }
        }
        index2 = n - 1;
        for(int i = 0; i < n; i++){
          if(ngnum != array1[i]){
            while(usecheck[index2]){
              index2--;
            }
            ansarray[i] = array2[index2];
            index2--;
          }
        }
      }
    }

    if(cancanclear){
      System.out.println("Yes");
      for(int i = 0; i < n - 1; i++){
        System.out.print(ansarray[i]);
        System.out.print(" ");
      }
      System.out.println(ansarray[n-1]);
    }else{
      System.out.println("No");
    }


  }
 
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
