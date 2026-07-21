import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n];
        a[0]=sc.nextInt();
        int min=Math.abs(a[0]);
        long sum=min;
        int fu=0;
        if(a[0]<0){
            fu++;
        }
        for(int i=1; i<n; i++){
            a[i]=sc.nextInt();
            if(a[i]<0){
                fu++;
            }
            int temp=Math.abs(a[i]);
            sum+=temp;
            if(min>temp){
                min=temp;
            }
        }

        if(fu%2==0){
            // System.out.println("0");
            System.out.println(sum);
        }else{
            // System.out.println(fu);
            System.out.println(sum-2*min);
        }
    }
}
