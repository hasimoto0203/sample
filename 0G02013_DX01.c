/* -------------------------------------------------------------------------- */
/* ファイル名：0G02013_DX01                                                        */
/* 作 成 日：2024/09/27                                                       */
/* 作 成 者：0G02013 志賀羊子                                                */
/* -------------------------------------------------------------------------- */
#include <stdio.h>
#include <math.h>
#define KAZU 20

int main(void)
{
	int numbers1[KAZU], numbers2[KAZU];	//20個の整数がはいった配列①②
	int sum1 = 0, sum2 = 0;	//合計値①②
	int max1, min1, max2, min2;	//最大値①②、最小値①②
	double heikin1, heikin2;		//平均値①②
	double bun1 = 0, bun2 = 0;	//分散①②
	double bun12 = 0;		//共分散
	double hyoujunn_hennsa1, hyoujunn_hennsa2;		//標準偏差①②
	double soukan_keisu;	//相関係数
	int sorted1[KAZU], sorted2[KAZU];		//昇順に並べ替える為にコピーして格納する
	int temp;	//昇順に並べ替えるときに一時的に格納する
	double tyuuouti1, tyuuouti2;		//中央値①②

	printf("%d個の整数を入力してください\n", KAZU);
	//20個の整数がはいった配列を入力する①
	for (int i = 1; i <= KAZU; i++) {
		
		printf("numbers1[%d]=", i);

		//整数以外が入力されたとき、再入力させる
		while (scanf("%d", &numbers1[i]) != 1) {
			printf("整数を入力してください。\n");
			while (getchar() != '\n'); // 入力バッファをクリア
		}

		//入力した値が0未満の時、再入力する
		while (numbers1[i] < 0) {
			printf("再入力してください\n");
			printf("numbers1[%d]=", i);
			scanf("%d", &numbers1[i]);
		}

		sorted1[i] = numbers1[i];
		sum1 += numbers1[i];		//合計値①を求める
	}

	printf("\n%d個の整数を入力してください\n", KAZU);
	//20個の整数がはいった配列を入力する②
	for (int i = 1; i <= KAZU; i++) {
		
		printf("numbers2[%d]=", i);

		//整数以外が入力されたとき、再入力させる
		while (scanf("%d", &numbers2[i]) != 1) {
			printf("整数を入力してください。\n");
			while (getchar() != '\n'); // 入力バッファをクリア
		}

		//入力した値が0未満の時、再入力する
		while (numbers2[i] < 0) {
			printf("再入力してください\n");
			printf("numbers2[%d]=", i);
			scanf("%d", &numbers2[i]);
		}

		sorted2[i] = numbers2[i];
		sum2 += numbers2[i];	//合計値②を求める
	}

	max1 = numbers1[1];		//最大値①にnumbers1[1]を設定
	min1 = numbers1[1];		//最小値①にnumbers1[1]を設定

	max2 = numbers2[1];		//最大値②にnumbers2[1]を設定
	min2 = numbers2[1];		//最小値②にnumbers2[1]を設定

	//最大値と最小値を求める①
	for (int i = 2; i <= KAZU; i++) {
		if (max1 < numbers1[i]) {
			max1 = numbers1[i];
		}
		if (min1 > numbers1[i]) {
			min1 = numbers1[i];
		}
	}

	//最大値と最小値を求める②
	for (int i = 2; i <= KAZU; i++) {
		if (max2 < numbers2[i]) {
			max2 = numbers2[i];
		}
		if (min2 > numbers2[i]) {
			min2 = numbers2[i];
		}
	}

	
	heikin1 = (double)sum1 / KAZU;	//平均値を求める①

	heikin2 = (double)sum2 / KAZU;	//平均値を求める②

	//分散を求める①②、共分散を求める
	for (int i = 1; i <= KAZU; i++) {	
		bun1 += pow(numbers1[i] - heikin1, 2);
		bun2 += pow(numbers2[i] - heikin2, 2);
		bun12 += (numbers1[i] - heikin1) * (numbers2[i] - heikin2);
	}
	
	hyoujunn_hennsa1 = sqrt(bun1 / KAZU);	//標準偏差を求める①

	hyoujunn_hennsa2 = sqrt(bun2 / KAZU);	//標準偏差を求める②

	soukan_keisu = bun12 / (KAZU * hyoujunn_hennsa1 * hyoujunn_hennsa2);	//相関係数を求める
	
	//コピーした配列を昇順に並び変える
	for (int i = 0; i < KAZU - 1; i++) {
		for (int j = i + 1; j < KAZU; j++) {
			if (sorted1[i] > sorted1[j]) {
				temp = sorted1[i];
				sorted1[i] = sorted1[j];
				sorted1[j] = temp;
			}
			if (sorted2[i] > sorted2[j]) {
				temp = sorted2[i];
				sorted2[i] = sorted2[j];
				sorted2[j] = temp;
			}
		}
	}

	tyuuouti1 = (KAZU % 2 == 0) ?
		(sorted1[KAZU / 2 - 1] + sorted1[KAZU / 2]) / 2.0 :
		sorted1[KAZU / 2];		//中央値①を求める
	tyuuouti2 = (KAZU % 2 == 0) ?
		(sorted2[KAZU / 2 - 1] + sorted2[KAZU / 2]) / 2.0 :
		sorted2[KAZU / 2];		//中央値②を求める

	printf("\n合計値1：%d\n", sum1);	//合計値を出力①
	printf("平均値1：%f\n", heikin1);	//平均値を出力①
	printf("最小値1：%d\n", min1);	//最小値を出力①
	printf("最大値1：%d\n", max1);	//最大値を出力①
	printf("中央値1：%f\n", tyuuouti1);		//中央値①を出力
	printf("標準偏差1：%f\n\n", hyoujunn_hennsa1);	//標準偏差を出力①

	printf("合計値2：%d\n", sum2);	//合計値を出力②
	printf("平均値2：%f\n", heikin2);	//平均値を出力②
	printf("最小値2：%d\n", min2);	//最小値を出力②
	printf("最大値2：%d\n", max2);	//最大値を出力②
	printf("中央値2：%f\n", tyuuouti2);		//中央値②を出力
	printf("標準偏差2：%f\n\n", hyoujunn_hennsa2);	//標準偏差を出力②

	printf("相関係数：%f\n", soukan_keisu);		//相関係数を出力

	return 0;

}