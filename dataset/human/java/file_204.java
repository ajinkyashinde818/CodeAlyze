import java.util.*;
public class Main{
        public static void main(String[] args){
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                int[] a = new int[n];
                int[] 鶏 = new int[n];
                int 負の数 = 0;
                for(int i = 0 ; i < n ; i++){
                        a[i] = sc.nextInt();
                        if(a[i] < 0) 負の数++;
                        鶏[i] = Math.abs(a[i]);
                }
                sc.close();
                Arrays.sort(a);
                
                long yoﾉ = 0;
                for(int i = 0 ; i < n ; i++){
                        yoﾉ += 鶏[i];
                }

                if(負の数 % 2 != 0){
                        if(負の数 == n) 負の数--;
                        yoﾉ += 2 * a[負の数 - 1];
                        yoﾉ = Math.max(yoﾉ , yoﾉ + 2 * Math.abs(a[負の数 - 1]) - 2 * Math.abs(a[負の数]));
                }
                sc.close();
                System.out.println(yoﾉ);
        }
}
