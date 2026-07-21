import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int maxDistance = arr[0]+k-arr[n-1];
        for(int i=1;i<n;i++){
            maxDistance = Math.max(maxDistance,arr[i]-arr[i-1]);
        }
        System.out.println(k-maxDistance);
    }
    
}
