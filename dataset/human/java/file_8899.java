import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();	//A
		int b = sc.nextInt();	//B
		int k = sc.nextInt();	//K
		int[] aS = new int[a];

		int aScnt = 0;
		for(int x=1;x<=a;x++){
			if(a%x==0){
				aS[aScnt] = x;
				aScnt++;
			}
		}
		aScnt--;
		int ans = 0;
		for(int x=b;x>0;x--){
			while(aS[aScnt]>x){
				aScnt--;
			}
			if(b%x==0&&aS[aScnt]==x){
				ans++;
				if(ans==k)break;
			}
		}
		System.out.println(aS[aScnt]);
	}
}
