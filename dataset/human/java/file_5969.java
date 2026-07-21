import java.util.*;
import java.util.Collections;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        int x = 0;

        for(int i=0; i<3; i++){
            if(S.charAt(i%3)!=S.charAt((i+1)%3)){
                x += 1;
            }
            else{
                System.out.println("No");
                break;
            }
        }
        if(x==3){
            System.out.println("Yes");
        }
    } 
}
