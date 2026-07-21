import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int i = 0;
        i += br.read();
        i += br.read();
        i += br.read();
        
        if(i == 294)
        System.out.println("Yes");
        else
        System.out.println("No");
    }

}
