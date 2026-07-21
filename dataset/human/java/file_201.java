import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        int[] a = new int [n]; 
        
        for(int i=0;i<n;i++){
            a[i]=scan.nextInt();
        }
        
        int min=2147483647;
        int count=0;
        long sum=0;
        
        for(int i=0;i<n;i++){
            if(a[i]<0){
                count++;
                sum-=a[i];
            }else{
                sum+=a[i];
            }
            if(Math.abs(a[i])<min){
                min=Math.abs(a[i]);
            }
        }
        
        if(count%2==1){
            sum-=2*min;
        }
        
        System.out.println(sum);
        
    }
}
