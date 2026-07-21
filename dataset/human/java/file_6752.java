import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author i.mekni
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        Scanner read = new Scanner(System.in);

        PrintWriter write = new PrintWriter(System.out);

        int k = read.nextInt();
        int n = read.nextInt();
        
        int max=0;
        int first=read.nextInt();
        int a=first;
        int b;
        for(int i=1;i<n;i++){
            b=read.nextInt();
            if(b-a>max) max=b-a;
            a=b;
        }
        if(k-a+first>max) max=k-a+first;
        write.println(k-max);
        write.close();
    }

}
