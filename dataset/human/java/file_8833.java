import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner stdIn = new Scanner(System.in);
        int a = stdIn.nextInt();
        int b = stdIn.nextInt();
        int k = stdIn.nextInt();
        int count = 0;
        int min;
        int[] num = new int[100];

        if(a>b) min = b;
        else min = a;
        for(int i=1;i<min+1;i++){
            if(a%i==0 && b%i==0) {
                num[count] = i;
                count++;
            }
        }
        System.out.println(num[count-k]);
    }
}
