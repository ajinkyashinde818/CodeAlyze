import java.util.*;

import java.lang.*;

import java.math.*;



public class Main {

	Scanner sc = new Scanner(System.in);

	void run(){

		int[] mga = {1,2,1,2,1,4,1,4};

		for(;sc.hasNextInt();){

			int[] machi = new int[8];

			for(int i=0;i<8;i++){

				machi[i] = sc.nextInt();

			}

			int min1 = Integer.MAX_VALUE;

			int min2 = Integer.MAX_VALUE;

			for(int i = 0; i < 8 ;i++){

				int sum = 0;

				int num = 0;

				for(int j = 0; j < 8 ; j++){

					sum += Math.max(0, machi[j]-mga[(i+j)&7]);

					num = num*10+mga[(i+j)&7];

				}

//				System.out.println(sum + " "+ num);

				if(sum < min1){

					min1 = sum;

					min2 = num;

				}else if(sum == min1){

					if(min2 > num){

						min2 = num;

					}

				}

			}

			char[] ch = String.valueOf(min2).toCharArray();

			String str = "";

			for(int i=0;i<8;i++){

				str += ch[i];

				str +=" ";

			}

			System.out.println(str.trim());

		}

		

	}

	public static void main(String[] args){

		Main m = new Main();

		m.run();

	}

}
