import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int N= scan.nextInt();
        int dis=0;
        int arr[]= new int[N];
        for(int i=0;i<N;i++){
           arr[i]= scan.nextInt();
        }
        for(int i=1;i<N;i++){
            int temp=Math.abs(arr[i]-arr[i-1]);
            dis=Math.max(dis,temp);
         }
         dis=Math.max(dis,Math.abs((x-arr[N-1])+arr[0]));
         
         x-=dis;
         System.out.println(x);
        
    }
    }
