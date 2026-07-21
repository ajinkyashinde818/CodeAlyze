import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int order = sc.nextInt();

        int cnt = 0, div = Math.min(num1, num2) + 1;
        while(cnt < order){
            div--;
            if(num1 % div == 0 && num2 % div == 0){
                cnt++;
            }
        }
        System.out.println(div);
    }
}
