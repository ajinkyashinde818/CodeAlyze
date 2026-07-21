import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt(),f=0;
    int[] d1=new int[n],d2=new int[n];
    for(int i=0;i<n;i++){
      d1[i]=sc.nextInt();
      d2[i]=sc.nextInt();
      if(d1[i]==d2[i]){
        f++;
        if(f==3){
          System.out.println("Yes");
          break;
        }
      }else{
        f=0;
      }
    }
    if(f<3){
      System.out.println("No");
    }
  }
}
