import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = 0;
        
        for(int i = 0;i < n;i++){
                int d1 = sc.nextInt();
                int d2 = sc.nextInt();
                
                
                if(d1 == d2){
                    c++;
                }else{
                    c = 0;
                }
                
                if(c >= 3){
                    System.out.println("Yes");
                    return;
                }
        }
        
        
        System.out.println("No");
        
        
    }
}
