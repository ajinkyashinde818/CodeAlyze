import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int R = sc.nextInt();
        sc.nextLine();

        if(N >= 10){
            System.out.println(R);
        }else if(0 < N && N < 10){
            System.out.println(R + (100*(10-N)));
        }
        sc.close();
    }
}
