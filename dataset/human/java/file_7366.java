import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        
        s = s.replaceAll("eraser","_");
        s = s.replaceAll("erase","_");
        s = s.replaceAll("dreamer","_");
        s = s.replaceAll("dream","_");
        s = s.replaceAll("_","");
        
        if(s.length() == 0){
            System.out.println("YES");
        }else{
            
            System.out.println("NO");
        }
            
    }
}
