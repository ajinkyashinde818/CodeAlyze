import java.io.*;
import java.util.*;

public class Main{
	public static void main(String args[]){
		try{
			new Main();
		}catch(IOException e){
			e.printStackTrace();
		}
	}

	public Main() throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		List<Integer> Ans = new ArrayList<Integer>();
		String line;

		while((line = in.readLine()) != null){
			int nTube = Integer.parseInt(line);

			if(nTube==0) break;

			Tube[] tubes = new Tube[nTube];
			for(int n=0; n<nTube; n++){
				line = in.readLine();
				String[] dst = line.split(" ");
				int x = Integer.parseInt(dst[0]);
				int y = Integer.parseInt(dst[1]);
				int r = Integer.parseInt(dst[2]);
				tubes[n] = new Tube(x, y, r);
			}

			line = in.readLine();
			int nSet = Integer.parseInt(line);
			for(int n=0; n<nSet; n++){
				line = in.readLine();
				String[] dst = line.split(" ");
				double x1 = Double.parseDouble(dst[0]);
				double y1 = Double.parseDouble(dst[1]);
				double x2 = Double.parseDouble(dst[2]);
				double y2 = Double.parseDouble(dst[3]);

				int hide = 0;
				for(int m=0; m<tubes.length; m++){
					double a, b, c, d, e1, e2, x0, min, max;
					if(x1 != x2){
						double p = (y1 - y2) / (x1 - x2);
						double q = y1 - p * x1;
						a = p * p + 1.0;
						b = 2.0 * p * (q - tubes[m].y) - 2.0 * tubes[m].x;
						c = Math.pow(tubes[m].x, 2.0) + Math.pow(q - tubes[m].y, 2.0) - Math.pow(tubes[m].r, 2.0);
						d = b * b - 4.0 * a * c;
						e1 = a * x1 * x1 + b * x1 + c;
						e2 = a * x2 * x2 + b * x2 + c;
						x0 = - b / (2.0 * a);
						min = Math.min(x1, x2);
						max = Math.max(x1, x2);
					}
					else{
						a = 1.0;
						b = -2.0 * tubes[m].y;
						c = Math.pow(tubes[m].y, 2.0) + Math.pow(x1 - tubes[m].x, 2.0) - Math.pow(tubes[m].r, 2.0);
						d = b * b - 4.0 * a * c;
						e1 = a * y1 * y1 + b * y1 + c;
						e2 = a * y2 * y2 + b * y2 + c;
						x0 = - b / (2.0 * a);
						min = Math.min(y1, y2);
						max = Math.max(y1, y2);
					}

					if(x0 >= min && x0 <= max){
						if(d*e1 >= 0 || d*e2 >= 0){
							Ans.add(1);
							hide = 1;
							break;
						}
					}
					else{
						if(e1 * e2 <= 0){
							Ans.add(1);
							hide = 1;
							break;
						}
					}
				}

				if(hide == 0){
					Ans.add(-1);
				}
			}
		}

		for(int n=0; n<Ans.size(); n++){
			int i = Ans.get(n);
			if(i==1){
				System.out.println("Safe");
			}else{
				System.out.println("Danger");
			}
		}
	}
}

class Tube{
	double x;
	double y;
	double r;

	public Tube(int x, int y, int r){
		this.x = (double)x;
		this.y = (double)y;
		this.r = (double)r;
	}
}
