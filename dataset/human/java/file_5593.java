import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(),k=sc.nextInt(),s=sc.nextInt();

        for(int i=0;i<k;i++){
            System.out.print(s+" ");
        }

        int other = 1000000000;
        if(s>=1000000000)other =1;
        for(int i=0;i<n-k;i++){
            System.out.print(other+" ");
        }

    }
}
