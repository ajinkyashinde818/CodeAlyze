import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int n=sc.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        int max=0;
        for(int i=0;i<n-1;i++){
            max=Math.max(max, nums[i+1]-nums[i]);
        }
        max=Math.max(max, nums[0]+k-nums[n-1]);
        System.out.println(k-max);
    }
    
}
