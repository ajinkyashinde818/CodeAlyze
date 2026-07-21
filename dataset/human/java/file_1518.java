import java.util.*;
public class Main {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
  int N = sc.nextInt();
  int M = sc.nextInt();
  String[] a = new String[N];
  String[] b = new String[M];
  boolean exist = false;
  for(int i = 0;i < N;i++)a[i] = sc.next();
  for(int i = 0;i < M;i++)b[i] = sc.next();
  out:
  for(int i = 0;i < N-M+1;i++) {
    for(int j = 0;j < N-M+1;j++) {
      for(int k = 0;k<M;k++) {
        if(!(a[j+k].substring(i,i+M).equals(b[k]))) break;
        if(k == M - 1) {
          exist = true;
          break out;
        }
      }
    }
  }
  if(exist) System.out.println("Yes");
  else System.out.println("No");
}}
