import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

class Main{


	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			String str;
			while((str = br.readLine()) != null){
				int n = Integer.parseInt(str);
				calc(n);
			}
		}catch(Exception e){
		}
	}

	static void calc(int n){
		switch(n){
		case 0:{
			System.out.println(0);
		}
		case 1:{
			System.out.println(1);
			break;
		}
		case 2:{
			System.out.println(2);
			break;
		}
		case 3:{
			System.out.println(5);
			break;
		}
		default:{
			if(n%2 == 0){
				int m = n/2 - 1;
				int result = 1;
				int edge = 3;
				for(int i = 0; i < m; i++){
					result += edge;
					edge *= 3;
				}
				System.out.println(result * 2);
			}else{
				int m = (n - 1) / 2;
				int result = 1;
				int edge = 4;
				for(int i = 0; i < m; i++){
					result += edge;
					edge *= 3;
				}
				System.out.println(result);
			}
		}
		}
	}
}
