import java.util.*;
public class Main {
        public static void main(String[] args){
                Scanner sc = new Scanner(System.in);
                int count = sc.nextInt();
                int dinner[] = new int[count];
                int dinner_fb[] = new int[count];
                int dinner_fb_p[] = new int[count - 1];
                for (int i = 0; i < count; i++) {
                        dinner[i] = sc.nextInt();
                }
                for (int i = 0; i < count; i++) {
                        dinner_fb[i] = sc.nextInt();
                }
                for (int i = 0; i < count - 1; i++) {
                        dinner_fb_p[i] = sc.nextInt();
                }

                int result = 0;
                int before_dinner = 0;
                for (int i = 0; i < dinner.length; i++) {
                        int dinner_count = dinner[i]-1;
                        if(before_dinner == dinner[i] - 1) {
                                if (before_dinner != 0) {
                                        result += dinner_fb_p[dinner_count - 1];
                                }

                        }
                        result += dinner_fb[dinner_count];
                        before_dinner = dinner[i];
                }
                System.out.println(result);
        }
}
