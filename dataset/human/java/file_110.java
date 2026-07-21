import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        long ans = 0;
        int count = 0;
        int min = 1000000000;
        for(int i = 0; i < n; i++){
            int a = Integer.parseInt(sc.next());
            if(a < 0){
                count++;
            }
            a = Math.abs(a);
            ans += a;
            if(a < min){
                min = a;
            }
        }
        
        if(count % 2 == 0){
            System.out.println(ans);
        }else{
            System.out.println(ans - (min*2));
        }
    }
}
