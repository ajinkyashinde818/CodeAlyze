import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int p[] = new int[110];
    int cnt=0;
    for(int i =0;i<110;i++){
      p[i]=100000000;
    }
    for(int i=0;i<100;i++){
      if(a%(i+1)==0&&b%(i+1)==0){
        p[i]=i+1;
        cnt=cnt+1;
      }
    }
    Arrays.sort(p);
//    for(int i=0;i<10;i++){
//    System.out.println(p[i]);
//      }
    System.out.println(p[cnt-k]);
      
      
  }
  

  
}
