import java.util.*;

public class Main {
    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int R = scanner.nextInt();
        
        int X = 100*(10-N);
        
        if(N>=10){
            System.out.println(R);
        }else{
            System.out.println(R+X);
        }
        
    }
}
