import java.util.*;
import java.lang.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int i = -1;
        if(a>b){
            i = b;
        }else{
            i = a;
        }
        int count = 0;
        while(true){
            if(a%i==0&&b%i==0){
                count++;
            }
            if(count == k){break;}
            i--;
        }
        System.out.println(i);
        sc.close();
    }
}
