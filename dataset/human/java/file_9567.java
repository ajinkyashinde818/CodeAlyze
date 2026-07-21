import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] arr = new int[n][2];
    for(int i=0;i<n;i++){
      arr[i][0]=sc.nextInt();
      arr[i][1]=sc.nextInt();
    }
    int max=0;
    int count=0;
    for(int i=0;i<n;i++){
      if(arr[i][1]==arr[i][0]){
        count++;
      }
      else{
        if(max<count){
          max=count;
        }
        count=0;
      }
    }
    if(max<count){
      max=count;
    }
    if(max>=3){
      System.out.println("Yes");
    }
    else{
      System.out.println("No");
    }
  }
}
