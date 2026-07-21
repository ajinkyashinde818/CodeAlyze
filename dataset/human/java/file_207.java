import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]po=new int[n];
        int minus=0;
        int zeros=0;
        for(int i=0;i<n;i++){
            po[i]=sc.nextInt();
            if(po[i]<0)minus++;
            else if(po[i]==0)zeros++;
            po[i]=Math.abs(po[i]);
        }
        if(minus%2==0||zeros!=0){
            long ans=0;
            for(int i=0;i<n;i++){
                ans+=po[i];
            }
            System.out.println(ans);
        }
        else{
            long ans=0;
            Arrays.sort(po);
            for(int i=1;i<n;i++){
                ans+=po[i];
            }
            System.out.println(ans-po[0]);
        }
    }
}
