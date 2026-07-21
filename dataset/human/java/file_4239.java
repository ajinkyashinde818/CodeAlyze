import java.io.BufferedReader;
import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;

public class Main {
	public static void main(final String[] args){
    
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        List<Integer> list3 = new ArrayList<>();
        int score = 0;

        for(int i = 0; i < n ; i++){
            list1.add(sc.nextInt());
        } 
        for(int i = 0; i < n ; i++){
            list2.add(sc.nextInt());
        } 
        for(int i = 0; i < n - 1; i++){
            list3.add(sc.nextInt());
        } 

        for(int i = 0 ; i < n ; i++){
            score += list2.get(list1.get(i)-1);
        }

        for(int i = 0 ; i < n - 1 ; i++){
            if(list1.get(i) == list1.get(i+1) - 1){
                score += list3.get(list1.get(i)-1);
            }
        }

        System.out.println(score);
        






    }
}
