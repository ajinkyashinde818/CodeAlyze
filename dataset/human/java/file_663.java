import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        
        if(N<10){
            int X = 100*(10-N);
            System.out.println(R+X);
        }else{
            System.out.println(R);
        }
    }
}
