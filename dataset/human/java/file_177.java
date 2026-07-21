import java.util.*;
 
public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n=sc.nextInt();
        int tmp;
        long sum=0;
        long minus=0;
        long min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            tmp=sc.nextInt();
            sum+=Math.abs(tmp);
            if(tmp<0){
                minus++;
            }
            min=Math.min(min,Math.abs(tmp));
        }
        System.out.println(minus%2==0?sum:sum-min*2);
    }
}
