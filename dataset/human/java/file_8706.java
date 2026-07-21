import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        //String s = sc.next();
        
        
        int k = Integer.parseInt(sc.next());
        int count =0;
        int i=b+1;
        while(count<k){
            i--;
            if((a%i==0)&&(b%i==0)) count++;
        }
        
        System.out.println(i);
    }
}
