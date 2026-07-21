import java.util.*;

public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
    
        int K =sc.nextInt();
        int N = sc.nextInt();
        Integer[]home = new Integer[N];
        for(int i=0;i<home.length;i++){
            home[i]=sc.nextInt();
        }
        
        int[]distance = new int[N];
        int ans=0;
        for(int i=0;i<N-1;i++){
            distance[i]=home[i+1]-home[i];
            ans+=distance[i];
        }
        distance[N-1]=K-home[N-1]+home[0];
        ans+=distance[N-1];
        
        Arrays.sort(distance);
        ans-=distance[N-1];
        System.out.println(ans);
        
    }
}
