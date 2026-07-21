import java.util.*;
import java.lang.Math; 

public class Main{
    public static void main(String[] args) {
        long count = 0;
        double quo = 1;
        int quo_max_n = 0;
        Scanner scan = new Scanner(System.in);
        double t = 0;
        t = scan.nextLong();
        
        for(int n=0;;n++){
            if(t < (Math.pow(3,n) - Math.pow(3,n-1) - 2)){
                quo_max_n = n-2;
                break;
            }
        }
        
        count = quo_max_n + 1;
        quo = Math.pow(3,quo_max_n);
        for( double tmp = t - (Math.pow(3,count)-1) / 2; tmp > 0; count++){
            if(tmp >= (quo - 1) * 3 / 2){
                tmp = tmp - quo;
                continue;
            }
            if(tmp < (quo - 1) * 3 / 2){
                quo = quo / 3;
                tmp = tmp - quo;
                continue;
            }
       }
       if(t == 0){
           count = 0;
       }
        System.out.println(count);
        scan.close();
    }
}
