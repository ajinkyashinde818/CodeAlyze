import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        int D = sc.nextInt();
        int G = sc.nextInt();
        
        int[] p = new int[D];
        int[] c = new int[D];
        
        for(int i = 0; i < D; i++){
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        
        int ans = Integer.MAX_VALUE;
        
        for(int i = 0; i < 1 << D; i++){
            
            int k = i;
            int j = 0;
            int score = 0;
            int count = 0;
            int greatestJ = 0;
            
            while(k > 0){
                if( (k & 1) == 1 ){
                    score += p[j]*(j+1)*100 + c[j];
                    count += p[j];
                } else{
                    greatestJ = j;
                }
                k >>= 1;
                j++;
            }
            
            if( score >= G ){
                ans = Math.min(ans, count);
            }else{
                
                int plus = 0;
                int index = 0;
                if( j == D ){
                    plus = (greatestJ+1) * 100;
                    index = greatestJ;
                } else {
                    plus = (D -1 + 1) * 100;
                    index = D - 1;
                }
                
                if( (int)Math.ceil((double)(G - score) / plus) <= p[index] - 1 ){
                    ans = Math.min( ans, count + (int)Math.ceil((double)(G - score) / plus) );
                }
            }
        }
        
        System.out.println(ans);
    }
}
