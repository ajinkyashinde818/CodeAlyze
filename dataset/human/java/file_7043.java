import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int n=sc.nextInt();
        int[]a=new int[n];
        int b[]=new int[n];
        a[0]=sc.nextInt();
        int max=a[0];
        for(int i=1;i<n;i++){
            a[i]=sc.nextInt();
            max=Math.max(a[i]-a[i-1],max);
        }
        max=Math.max(a[0]+(k-a[n-1]),max);
        System.out.println(k-max);
    }
}
