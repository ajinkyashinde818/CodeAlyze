import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);        
        int N = sc.nextInt();
        int R = sc.nextInt();
        
        if(N>=10){
            System.out.println(R);
        }else{
            System.out.println(R+100*(10-N));
        }
    }
}
