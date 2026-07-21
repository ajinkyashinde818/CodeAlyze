import java.io.*;
import java.util.*;
import java.util.stream.*;

class Main{
	static final long MOD = 1_000_000_007; // 10^9+7
    static final int MAX = 2_147_483_646; // intMax 
    static final int INF = 1_000_000_000; // 10^9  
    public static void main(String[] args) throws Exception {
		hayami saori = new hayami();
		int n = saori.saori_hayami();
		long k = saori.saorihayami();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = saori.saori_hayami()-1;
		}
		HashSet<Integer> roop = new HashSet<>();
		int num = a[0];
		int count = 1;
		roop.add(0);
		for(int i = 1;i < MAX;i++){
			if(roop.contains(num)) break;
			count++;
			roop.add(num);
			num = a[num];
		}
		int fnum = 0;
		int endnum = 0;
		int num2 = 0;
		roop.add(0);
		roop = new HashSet<>();
		for(int i = 0;i < MAX;i++){
			if(i == 0){
				num2 = a[0];
				roop.add(0);
			} else {
				num2 = a[num2];
			}
			if(!roop.contains(num) && num2 == num){
				fnum = i+1;
			}
			if(roop.contains(num) && num2 == num){
				endnum = i+1;
				break;
			}
			if(i == 0){
				roop.add(0);
			} else {
				roop.add(num2);
			}
			
		}
		int aida = endnum - fnum;
		int ans = a[0];
		if(k > fnum){
			k = k-fnum;
			k = k % aida;
		if(k ==0)k = aida;
		ans = a[num];
		}
		
		
		for(int i = 1;i <k;i++){

			ans = a[ans];
		}
		System.out.println(ans+1);
		saori.close();
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
