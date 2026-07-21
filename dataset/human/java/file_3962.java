import java.util.Scanner;

public class Main {

	private static Scanner mScanner;

	public static void main(String[] args) {

		mScanner = new Scanner(System.in);

		//料理の種類の合計をセット
		int intDishTotal = mScanner.nextInt();

		//食べた料理の順番をセット
		int[] intArrEatOrder = CreateArrayFromInput(intDishTotal);

		//各料理の満足度Bをセット
		int[] intArrSatisfactionB = CreateArrayFromInput(intDishTotal);

		//各料理の満足度Cをセット
		int[] intArrSatisfactionC = CreateArrayFromInput(intDishTotal - 1);

		//満足度合計
		int intSatisFactionSum = 0;

		//料理No.履歴（前回食べた料理No.）
		int intDishNoHistory = 0;

		for(int i = 0; i < intArrEatOrder.length; i++) {

			//料理No.を取得
			int intDishNo = intArrEatOrder[i];

			//満足度Bを追加
			intSatisFactionSum += intArrSatisfactionB[intDishNo - 1];

			if(intDishNoHistory != 0 && intDishNoHistory == (intDishNo - 1)) {

				//満足度Cを追加
				intSatisFactionSum += intArrSatisfactionC[intDishNoHistory - 1];
			}

			//料理No.履歴を更新
			intDishNoHistory = intDishNo;

		}

		//アウトプット
		System.out.println(intSatisFactionSum);

	}

	//-----------------------------------------------------------
	//	コンソールで入力した値から配列を生成する
	//-----------------------------------------------------------
	private static int[] CreateArrayFromInput(int intInCount) {

		int[] intArrRet = new int[intInCount];

		for (int i = 0; i < intInCount; i++) {
			intArrRet[i] = mScanner.nextInt();
		}

		return intArrRet;
	}

}
