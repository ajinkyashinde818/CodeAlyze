import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n=sc.nextLong();
        if(n%2==1){
            System.out.println(0);
            return;
        }
        n/=2;
        long ans=0;
        long i=1;
        while(n>=Math.pow(5, i)){
            ans+=(long)(n/(long)Math.pow(5, i));
            i++;
        }
        System.out.println(ans);
        

    }



}
