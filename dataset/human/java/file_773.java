import java.util.*;


class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();


        if(n>=10){
            System.out.println(k);
            return;
        }

        int hoge=k+100*(10-n);
        System.out.println(hoge);


    }
}
