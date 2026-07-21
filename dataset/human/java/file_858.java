import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeSet;

public class Main{
       
	public static void main(String[] args) {
		Scanner sdf = new Scanner(System.in);
		
                int t=1;
                while(t-->0){
                    int n=sdf.nextInt();
                    int r=sdf.nextInt();
                    if(n>=10){
                        System.out.println(r);
                        return;
                    }
                    r=r+100*(10-n);
                    System.out.println(r);
                        
                
                }                
        }
   


}
