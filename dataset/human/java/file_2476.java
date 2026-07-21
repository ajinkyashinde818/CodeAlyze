import java.util.Scanner;


public class Main {
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		while(true){
			
			int n = sc.nextInt();
			
			String[] line = new String[n];
			sc.nextLine();
			
			for(int i = 0; i < n; i++){
				line[i] = sc.nextLine();
			}
			
			for(int i = 0; i < n; i++){
				String[] linespl = line[i].split(" ");
				int calcsum = 0;
				for(int j = 0; j < linespl.length; j++){
					int soeji = 1;
					for(int k = 0; k < linespl[j].length(); k++){
						if(linespl[j].charAt(k) == 'm' || linespl[j].charAt(k) == 'c' || linespl[j].charAt(k) == 'x' || linespl[j].charAt(k) == 'i'){
							calcsum = calcsum + calc(soeji, linespl[j].charAt(k));
							soeji = 1;
						}else{
							soeji = new Integer(linespl[j].charAt(k) - '0');
						}
					}
					
				}	
				int up;
				while(true){
					if(calcsum >= 1000){
						up = calcsum/1000;
						if(up == 1){
							System.out.print("m");
						}else{
							System.out.print(up + "m");
						}
						calcsum = calcsum%1000;
					}else if(calcsum >= 100){
						up = calcsum/100;
						if(up == 1){
							System.out.print("c");
						}else{
							System.out.print(up + "c");
						}
						calcsum = calcsum%100;
					}else if(calcsum >= 10){
						up = calcsum/10;
						if(up == 1){
							System.out.print("x");
						}else{
							System.out.print(up + "x");
						}
						calcsum = calcsum%10;
					}else{
						if(calcsum == 1){
							System.out.println("i");
						}else{
							System.out.println(calcsum + "i");
						}
						break;	
					}
					
					if(calcsum == 0){
						System.out.println("");
						break;
					}
				}

				
			}
			break;
			
		}
		
	}

	private static int calc(int soeji, char charAt) {
		
		if(charAt == 'm'){
			return 1000 * soeji;
		}else if(charAt == 'c'){
			return 100 * soeji;
		}else if(charAt == 'x'){
			return 10 * soeji;
		}else if(charAt == 'i'){
			return soeji;
		}
		return 0;
	}

}
