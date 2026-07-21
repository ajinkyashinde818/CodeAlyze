import java.util.Scanner;
public class Main{
    public static void main(String args[]) {
        int num;
        Scanner scan = new Scanner(System.in);
        num = scan.nextInt();
        int jyun[] = new int[num];
        int manzoku[] = new int[num];
        int tuika[] = new int[num-1];
        for(int i = 0; i< num ;i++){
            jyun[i] = scan.nextInt();
        }
        for(int i = 0; i< num;i++){
            manzoku[i] = scan.nextInt();
        }
        for(int i = 0; i< num -1;i++){
            tuika[i] = scan.nextInt();
        }
        int sum = 0;
        for(int i = 0;i < num;i++){
            sum = sum + manzoku[i];
        }
        for(int i = 0;i < num -1;i++){
            if(jyun[i] == jyun[i+1]-1){
                sum = sum + tuika[jyun[i]-1];
            }
        }
        System.out.println(sum);

    }

}
