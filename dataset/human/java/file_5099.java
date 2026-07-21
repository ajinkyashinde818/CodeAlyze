import java.util.*;

public class Main{
    
    static final int MOD = (int)1e9+7;
    static final int MAX = (int)1e5+5;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        int q = Integer.parseInt(sc.next());
        int r = 0;
        StringBuffer[] z = new StringBuffer[2];
        for(int i=0; i<2; i++){
            z[i] = new StringBuffer();
        }
        
        for(int i=0; i<q; i++){
            int t = Integer.parseInt(sc.next());
            if(t==1){
                r ^= 1;
            }else{
                int f = Integer.parseInt(sc.next());
                String c = sc.next();
                z[(r+f)%2].append(c);
            }
        }
        
        if(r==0){
            System.out.print(z[1].reverse().toString());
            System.out.print(s);
            System.out.print(z[0].toString());
        }else{
            System.out.print(z[0].reverse().toString());
            System.out.print(reverse(s));
            System.out.print(z[1].toString());
        }
        
        System.out.println();
    }
    
    public static String reverse(String s){
        StringBuffer sb = new StringBuffer(s);
        return sb.reverse().toString();
    }
    
}
