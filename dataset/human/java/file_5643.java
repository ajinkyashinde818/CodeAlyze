import java.util.*;
 
public class Main {
    public static void main(String args[]){
        Scanner stdIn = new Scanner(System.in);
 
        int n = stdIn.nextInt();
        int k = stdIn.nextInt();
        int s = stdIn.nextInt();
        //int x = stdIn.nextInt();
        //int x[] = new int[n];
        //int l[] = new int[n];
        //String s = stdIn.next();
        //String t = stdIn.next();
        //char c[] = s.toCharArray();
        
        //c[0] += 1;
        //int sum = 0;
        //boolean flag = true;
        
        for(int i = 0; i < n - 1; i++){
            if(i < k){
                System.out.print(s + " ");
            }else if(s == 1000000000){
                System.out.print((s - 1) + " ");
            }else{
                System.out.print((s + 1) + " ");
            }
            
        }
        
        for(int i = n - 1; i < n; i++){
            if(i < k){
                System.out.println(s);
            }else if(s == 1000000000){
                System.out.println(s - 1);
            }else {
                System.out.println(s + 1);
            }
        }
        
        //System.out.println();
        //System.out.print();
 
        stdIn.close();
    }
}
