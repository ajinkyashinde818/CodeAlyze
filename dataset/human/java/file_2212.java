import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N=sc.nextLong();
        boolean one = false;
        if(N==1) {
            one=true;
        }

        List<Integer[]> numbers = new ArrayList<Integer[]>();


        for(int i=2; i<1000000; i++) {
            int count=0;
            while(N%i==0) {
                N/=i;
                count++;
            }
            if(count!=0) {
                Integer[] prime = {i,count};
                numbers.add(prime);
            }
        }

        if(one) {
            System.out.println(0);
        }else if(numbers.isEmpty()) {
            System.out.println(1);
        }else{
            int count=0;
            for(Integer[] inside : numbers) {
                int minus = 1;
                while(true) {
                    if(inside[1]>=minus) {
                        count++;
                        inside[1]-=minus;
                        minus++;
                    }else {
                        break;
                    }
                }
            }
            if(N==1) {
                System.out.println(count);
            }else {
                System.out.println(count+1);
            }
        }

    }

}
