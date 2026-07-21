import java.util.Scanner;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int d1 = 0;
        int d2 = 0;
        boolean[] boo = new boolean[n];
        boolean result = false;

        for(int i = 0; i < n; i++){
            d1 = sc.nextInt();
            d2 = sc.nextInt();

            if(d1 == d2){
                boo[i] = true;
            }
            else{
                boo[i] = false;
            }
        }

        for(int i = 0; i < n-2; i++){
            if(boo[i] && boo[i+1] && boo[i+2]){
                result = true;
            }
        }

        if(result == true){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }    
}
