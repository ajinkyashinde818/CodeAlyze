import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int q = sc.nextInt();
        if(p == 0){
            if(q <= 1911){
                System.out.println("M" + (q - 1867));
            }
            else if(q <= 1925){
                System.out.println("T" + (q - 1911));
            }
            else if(q <= 1988){
                System.out.println("S" + (q - 1925));
            }
            else{
                System.out.println("H" + (q - 1988));
            }
        }
        else if(p == 1){
            System.out.println(1867 + q);
        }
        else if(p == 2){
            System.out.println(1911 + q);
        }
        else if(p == 3){
            System.out.println(1925 + q);
        }
        else System.out.println(1988 + q);
    }



}
