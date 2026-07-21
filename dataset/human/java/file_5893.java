import java.util.*;
import java.io.*;
 
public class Main{
    public static void main(String[] args){
        Main m = new Main();
        m.input();
        m.solve();
        m.out();
    }
    
    boolean ac,bc,cc;
    public void input(){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String[] asp = a.split("");
        
        ac = bc = cc = false;

        for(int i = 0; i < 3; i++){
            if(asp[i].equals("a")){
                ac = true;
            }else if(asp[i].equals("b")){
                bc = true;
            }else if(asp[i].equals("c")){
                cc = true;
            }
        }
        
        sc.close();
    }
    
    public void solve(){
        
    }
    
    public void out(){
        if(ac && bc && cc){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
