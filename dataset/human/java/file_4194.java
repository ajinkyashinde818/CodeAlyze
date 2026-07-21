import java.util.Scanner;
public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int e[] = new int[a];
    int b[] = new int[a];
    int c[] = new int[a-1];
    int d = 0;
    int s = 0;
    for(int i = 0; i < a; i++){
      e[i] = sc.nextInt();
      if(i != 0){
        while(e[i] == e[i-1]){
          e[i] = sc.nextInt();
        }
      }
    }
    for(int i = 0; i < a; i++){
      b[i] = sc.nextInt();
    }
    for(int i = 0; i < a - 1; i++){
      c[i] = sc.nextInt();
    }
    for(int i = 0; i < a; i++){
      s = s + b[e[i]-1];
      if(d == e[i]-1 && i != 0){
        s = s + c[e[i-1]-1];
      }
      d = e[i];
    }
    System.out.println(s);
  }
}
