import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner stdIn = new Scanner(System.in);
        int n = stdIn.nextInt();
        int r = stdIn.nextInt();
        // int c = stdIn.nextInt();
        // String s = stdIn.next();
        // boolean flag = true;
        
        // int num[] = new int[n];
        
        // for(int i = 0; i < n; i++){
        //     num[i] = stdIn.nextInt();
        // }
        
        // char c[] = s.toCharArray();
        
        // for(int i = 0; i < s.length(); i++){
        //     c[i];
        // }
        
        
        if(n >= 10){
            System.out.println(r);
        }else{
            System.out.println(r + (10 - n) * 100);
        }
        
        // if(flag){
        //     System.out.println("Yes");
        // }else{
        //     System.out.println("No");
        // }
        
        // System.out.println();
        // System.out.print();
    }
}
