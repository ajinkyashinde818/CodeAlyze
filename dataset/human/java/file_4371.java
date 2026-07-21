import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        int[]b=new int[n];
        int[]c=new int[n-1];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt()-1;
        }
        for(int i=0;i<n;i++){
            b[i]=sc.nextInt();
        }
        for(int i=0;i<n-1;i++){
            c[i]=sc.nextInt();
        }
        int index=-2;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=b[a[i]];
            if(index+1==a[i]){
                ans+=c[a[i]-1];
            }
            index=a[i];
        }
        System.out.println(ans);
    }
}
