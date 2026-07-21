import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    void run(String[] args){
        Scanner scan=new Scanner(System.in);
        Integer count=scan.nextInt();
        Integer one;
        Integer two;
        Integer i;
        ArrayList<Integer>ones=new ArrayList<>();
        ArrayList<Integer>twos=new ArrayList<>();
        ArrayList<Integer>counts=new ArrayList<>();
        for(i=0;i<count;i++){
            one=scan.nextInt();
            two=scan.nextInt();
            ones.add(one);
            twos.add(two);
        }
        for(i=0;i<count;i++){
            if(ones.get(i)==twos.get(i)){
                counts.add(1);
            }
            else{
                counts.add(0);
            }
        }
        print(count,counts);
    }
    Integer print(Integer count,ArrayList<Integer>counts){
        Integer i;
        for(i=0;i<count-2;i++){
            if((1==counts.get(i))&&(counts.get(i)==counts.get(i+1))&&(counts.get(i+1)==counts.get(i+2))){
                System.out.println("Yes");
                return 0;
            }
        }
        System.out.println("No");
        return 0;
    }
    public static void main(String args[]){
        Main printer = new Main();
        printer.run(args);
    }
}
