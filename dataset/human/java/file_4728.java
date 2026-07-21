import java.util.*;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String N = sc.next();
        int ans = 0;
        int counter = 0;

        for (int i = N.length(); i > 0; i--) {
            int n = Integer.parseInt(N.substring(i-1,i)) + counter;

            counter = 0;
            if(n == 10) {
                counter = 1;
                n = 0;
            }

            if(10 - n <= n){
                if(i > 1 && Integer.parseInt(N.substring(i-2,i-1)) < 5 && n == 5){
                    ans += 5;
                    //System.out.println("P" + (N.length() -i) + ":" +5);
                } else if(i == 1 && n == 5) {
                    ans += 5;
                } else{
                        counter = 1;
                        ans += 10 -n;
                        //System.out.println("R" + (N.length() -i) + ":" +Math.min(n, 10 - n));
                    }


            } else {
                ans += n;
               //System.out.println("P" + (N.length() -i) + ":" +Math.min(n, 10 - n));
            }

        }
        if(counter == 1){
            ans++;
           // System.out.println("P"  + N.length() + ":" +1);
        }
        System.out.println(ans);
    }

}
