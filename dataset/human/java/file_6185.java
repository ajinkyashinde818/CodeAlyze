import java.util.*;
 
 
class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int K = sc.nextInt();
        int S = sc.nextInt();
 
        int sum = 0;
 
        for(int x = 0;x <= K;x++){
            if(x > S) break;
           for(int y = 0;y <= K;y++){
               if(x + y > S) break;
               int z = S -x - y;
               if(z >= 0 && z <= K) sum++;
               }
           } 
        
        System.out.println(sum);
    }
}
