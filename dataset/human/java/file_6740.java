import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k =0,n=0,sum=0,max=-1000;
    if(sc.hasNext())
    k= sc.nextInt();
    n= sc.nextInt();
    int[] arr = new int[n];
    for(int i=0;i<n;i++){
        arr[i] = sc.nextInt();
    }
    int[] dist = new int[n];
    for(int i=0;i<n-1;i++){
        dist[i] = arr[i+1]-arr[i];
        sum += dist[i];
        if(dist[i]>max){
            max=dist[i];
        }
    }
    dist[n-1]=k-sum;
    sum += dist[n-1];
    if(dist[n-1]>max){
        max=dist[n-1];
    }
    sum=sum-max;

    System.out.println(sum);
  }
}
