import java.util.*;
 
public class Main {
    static final long MOD=1000000007;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        long[] nums=new long[n];
        nums[0]=sc.nextInt();
        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+sc.nextInt();
        }
        long output=Long.MAX_VALUE;
        for(int i=0;i<n-1;i++){
            output=Math.min(output, Math.abs(nums[n-1]-nums[i]*2));
        }
        System.out.println(output);
    }
}
