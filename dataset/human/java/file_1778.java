import java.io.*;
import java.util.*;
class Main{
    public static void main(String[] args) throws Exception {
		hayami saori = new hayami();
		int D = saori.saori_hayami();
		int G = saori.saori_hayami();
		int[] p = new int[D];
		int[] c = new int[D];
		

		for(int i = 0;i < D;i++){
			p[i] = saori.saori_hayami();
			c[i] = saori.saori_hayami();
		}
		int ans = G/100;
		

		for(int i = 0; i < Math.pow(2, D);i++){
			HashSet<Integer> hs = new HashSet<>();
			int sum = 0;
			int hayami = 0;
			for(int j = 0; j < D ; j++){
				if ((1 & i >> j) == 1) {
					sum += 100*(j+1)*p[j] + c[j];
					hayami += p[j];
					hs.add(j);
                }
			}
			a:if(sum < G){
				for(int j = D-1;j >= 0;j--){
					if (hs.contains(j)) continue;
					for(int m = 0;m < p[j];m++){
						sum+=100*(j+1);
						hayami++;
						if(sum >= G)break a;
					}
				}
			}
			ans = Math.min(ans, hayami);
		}
		System.out.println(ans);
		
    }
}

class hayami implements Closeable {
	private final InputStream in = System.in;
	private final byte[] hayami = new byte[1024];
	private int Hayami = 0;
	private int saori = 0;
	private boolean HayamiSaori() {
		if (Hayami < saori) {
			return true;
		}else{
			Hayami = 0;
			try {
				saori = in.read(hayami);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (saori <= 0) {
				return false;
			}
		}
		return true;
	}
	private int SaoriHayami() { 
		if (HayamiSaori()) {
            return hayami[Hayami++];
         }else{
             return -1;
         }
	}
	private static boolean hayami_saori(int hayami) { 
		return 33 <= hayami && hayami <= 126;
	}
	public boolean hayamisaori() { 
		while(HayamiSaori() && !hayami_saori(hayami[Hayami])) Hayami++; return HayamiSaori();
	}
	public String nextHayami() {
		if (!hayamisaori()) throw new NoSuchElementException();
		StringBuilder hayamin = new StringBuilder();
		int saori = SaoriHayami();
		while(hayami_saori(saori)) {
			hayamin.appendCodePoint(saori);
			saori = SaoriHayami();
		}
		return hayamin.toString();
	}
	public long saorihayami() {//nextLong
		if (!hayamisaori()) throw new NoSuchElementException();
		long hayami = 0;
		boolean misao = false;
		int saori = SaoriHayami();
		if (saori == '-') {
			misao = true;
			saori = SaoriHayami();
		}
		if (saori < '0' || '9' < saori) {
			throw new NumberFormatException();
		}
		while(true){
			if ('0' <= saori && saori <= '9') {
				hayami *= 10;
				hayami += saori - '0';
			}else if(saori == -1 || !hayami_saori(saori)){
				return misao ? -hayami : hayami;
			}else{
				throw new NumberFormatException();
			}
			saori = SaoriHayami();
		}
	}
	public int saori_hayami() {//nextInt
		long hayami = saorihayami();
		if (hayami < Integer.MIN_VALUE || hayami > Integer.MAX_VALUE) throw new NumberFormatException();
		return (int) hayami;
	}
	public double Hayamin() { //nextDouble
		return Double.parseDouble(nextHayami());
	}
	public void close() {
		try {
			in.close();
		} catch (IOException e) {
		}
    }
    
}
