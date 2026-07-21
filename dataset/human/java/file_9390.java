import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
    
        var sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        
        boolean yes = false;
        int count = 0;
        for(int i = 0; i < n; i++){
            int d1 = Integer.parseInt(sc.next());
            int d2 = Integer.parseInt(sc.next());
            if(d1 == d2){
                count++;
                if(count == 3){
                    yes = true;
                }
            }else{
                count = 0;
            }
        }
    
        System.out.println(yes ? "Yes" : "No");
    }
}
