import java.util.*;
import java.io.*;
 
public class Main{
    static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int R = Integer.parseInt(sc.next());
        if(N >= 10){
            System.out.println(R);
        }else{
            System.out.println((100*(10-N)+R));
        }
       
    }
}
