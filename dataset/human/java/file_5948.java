import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner stdIn = new Scanner(System.in);
        
        //int a = stdIn.nextInt();
        //int b = stdIn.nextInt();
        //int x = stdIn.nextInt();
        //int num[] = new int[3];
        String s = stdIn.next();
        char c[] = s.toCharArray();
        //int sum = 0;
        //boolean flag = true;
        //for(int i = 0; i < s.length(); i++){
        //}
        
        Arrays.sort(c);
        
        if(c[0] == 'a' && c[1] == 'b' && c[2] == 'c'){
        	System.out.println("Yes");
        }else{
        	System.out.println("No");
        }
        
        //System.out.println();
        //System.out.print();
    }
}
