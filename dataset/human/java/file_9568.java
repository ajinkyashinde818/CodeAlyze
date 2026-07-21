import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] d1 = new int[N];
        int[] d2 = new int[N];
        int count = 0;
        String ans = "No";
        for(int i=0;i<N;i++){
            d1[i] = sc.nextInt();
            d2[i] = sc.nextInt();
            if(d1[i] == d2[i]){
                count++;
            }else{
                count = 0;
            }
            if(count == 3){
                ans = "Yes";
                break;
            }
        }
        System.out.println(ans);
    }
}
