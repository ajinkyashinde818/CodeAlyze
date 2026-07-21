import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();

        Queue<Integer[]> a_num = new ArrayDeque<Integer[]>();
        Queue<Integer[]> b_num = new ArrayDeque<Integer[]>();

        int a_counter = 0;
        int b_counter = 0;
        long answer = 1;

        for(int i=2; i<3200; i++) {
            a_counter=0;
            b_counter=0;

            while(A%i==0) {
                A/=i;
                a_counter++;
            }
            if(a_counter!=0) {
                Integer[] nums = {i,a_counter};
                a_num.add(nums);
            }
            while(B%i==0) {
                B/=i;
                b_counter++;
            }
            if(b_counter!=0) {
                Integer[] nums = {i,b_counter};
                b_num.add(nums);
            }
        }
        if(a_num.isEmpty()) {
            Integer[] nums = {A,1};
            a_num.add(nums);
        }else if(A!=1) {
           Integer[] nums = {A,1};
           a_num.add(nums);
        }
        if(b_num.isEmpty()) {
            Integer[] nums = {B,1};
            b_num.add(nums);
        }else if(B!=1) {
           Integer[] nums = {B,1};
           b_num.add(nums);
        }

        Integer[] a_max= {100001,1};
        a_num.add(a_max);
        Integer[] b_max= {100001,1};
        b_num.add(b_max);
        Integer[] a_tmp=a_num.poll();
        Integer[] b_tmp=b_num.poll();


        while(a_tmp[0]!=100001 || b_tmp[0]!=100001) {
            if(a_tmp[0]<b_tmp[0]) {
                for(int i=0;i<a_tmp[1]; i++) {
                    answer*=a_tmp[0];
                }
                a_tmp=a_num.poll();
            }else if(a_tmp[0]>b_tmp[0]) {
                for(int i=0;i<b_tmp[1]; i++) {
                    answer*=b_tmp[0];
                }
                b_tmp=b_num.poll();
            }else {
                if(a_tmp[1]>=b_tmp[1]) {
                    for(int i=0;i<a_tmp[1]; i++) {
                        answer*=a_tmp[0];
                    }
                }else {
                    for(int i=0;i<b_tmp[1]; i++) {
                        answer*=b_tmp[0];
                    }
                }
                a_tmp=a_num.poll();
                b_tmp=b_num.poll();
            }
        }

        System.out.println(answer);


    }

}
