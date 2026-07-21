import java.util.Scanner;

class Main {
    static Scanner sc;
    public static void main(String[] args) {
        
        sc = new Scanner(System.in);
        int N = parseInt();
        int R = parseInt();

        if (N> 10){
            System.out.println(R);
        }else{
            System.out.println((R + (100*(10-N))));
        }
    }

    public static int parseInt(){
        return Integer.parseInt(sc.next());
    }
}
