import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int count = 0;

        for(int x=0; x<k+1; x++){
            for(int y=0; y<k+1; y++){
                if(s-x-y<k+1 && s-x-y>=0){
                    count++;
                }

            }
        }


        System.out.println(count);


    }
}
