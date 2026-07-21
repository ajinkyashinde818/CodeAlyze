import java.util.*;
 
public class Main {
    public static void main(String args[]){
        Scanner stdIn = new Scanner(System.in);
        
        int k = stdIn.nextInt();
        int n = stdIn.nextInt();
        
        int max = 0;
        int a[] = new int[n];
        
        for(int i = 0; i < n; i++){
            a[i] = stdIn.nextInt();
        }
        
        Arrays.sort(a);
        
        for(int i = 0; i < n - 1; i++){
            if(max < a[i + 1] - a[i]){
                max = a[i + 1] - a[i];
            }
        }
        
        int gyaku = a[0] + k - a[n - 1];
        //boolean flag = true;
        
        // for(int i = 0; i < s.length(); i++){
        //     a[i] = c[i] - 48;
        //     System.out.println(a[i]);
        // }
        //int sum = 0;
        //boolean flag = true;
        //for(int i = 0; i < s.length(); i++){
        //}
        
        System.out.println(Math.min(k - gyaku, k - max));
 
        //System.out.println();
        //System.out.print();
 
        stdIn.close();
    }
}
