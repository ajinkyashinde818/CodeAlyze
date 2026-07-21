import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k= sc.nextInt();
    int s = sc.nextInt();
    int cnt=0,z;
    for(int x=0;x<=k;x++){
      for(int y=0;y<=k;y++){
        z=s-(x+y);
        if(k>=z&&z>=0) cnt++;
      }
    }
    System.out.println(cnt);
  }
}
