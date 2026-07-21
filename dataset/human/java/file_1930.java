import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int d = Integer.parseInt(sc.next());
        int g = Integer.parseInt(sc.next());
        int[] p = new int[d];
        int[] c = new int[d];
        for(int i = 0; i < d; i++){
            p[i] = Integer.parseInt(sc.next());
            c[i] = Integer.parseInt(sc.next());
        }
        
        int min = 1000;
        for(int i = 0; i < 1<<d; i++){
            int ac = 0;
            int point = 0;
            int a = -1;
            for(int j = 0; j < d; j++){
                if((i>>j & 1) == 1){
                    ac += p[j];
                    point += (j+1)*100*p[j] + c[j];
                }else{
                    a = j;
                }
            }
            if(point < g && a != -1){
                if(g - point <= (a+1)*100*(p[a]-1)){
                    int b = (g - point + (a+1)*100 -1) / ((a+1)*100);
                    ac += b;
                    point += (a+1)*100*b;
                }
            }
            if(point >= g && ac < min){
                min = ac;
            }
        }
        System.out.println(min);
    }
}
