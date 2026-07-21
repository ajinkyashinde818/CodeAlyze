import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int A=sc.nextInt();
        int B= sc.nextInt();
        int C=sc.nextInt();
        int gedoku = A+B;
        int max=0;
        if(gedoku<C) max = gedoku+B+1;
        else if(gedoku==C) max = gedoku+B;
        else max = C+B;
        System.out.println(max);
    }
}
