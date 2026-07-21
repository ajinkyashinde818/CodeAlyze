import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        int flag = 0;
        for(int i=0;i<n;i++){
            int d1 = sc.nextInt();
            int d2 = sc.nextInt();
            if(d1==d2){
                count++;
                if(count==3)flag=1;
            }else{
                count = 0;
            }
        }
        if(flag==1){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
