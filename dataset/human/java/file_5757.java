import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {


            String line =br.readLine();
            
            
        int cnt =0;
        
        if(line.contains("a")){
            cnt++;
        }
        if(line.contains("b")){
            cnt++;
        }
        if(line.contains("c")){
            cnt++;
        }
        
        if(cnt==3){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
            
            






        }
    }
}
