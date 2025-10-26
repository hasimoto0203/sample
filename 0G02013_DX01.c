/* -------------------------------------------------------------------------- */
/* �t�@�C�����F0G02013_DX01                                                        */
/* �� �� ���F2024/09/27                                                       */
/* �� �� �ҁF0G02013 �u��r�q                                                */
/* -------------------------------------------------------------------------- */
#include <stdio.h>
#include <math.h>
#define KAZU 20

int main(void)
{
	int numbers1[KAZU], numbers2[KAZU];	//20�̐������͂������z��@�A
	int sum1 = 0, sum2 = 0;	//���v�l�@�A
	int max1, min1, max2, min2;	//�ő�l�@�A�A�ŏ��l�@�A
	double heikin1, heikin2;		//���ϒl�@�A
	double bun1 = 0, bun2 = 0;	//���U�@�A
	double bun12 = 0;		//�����U
	double hyoujunn_hennsa1, hyoujunn_hennsa2;		//�W���΍��@�A
	double soukan_keisu;	//���֌W��
	int sorted1[KAZU], sorted2[KAZU];		//�����ɕ��בւ���ׂɃR�s�[���Ċi�[����
	int temp;	//�����ɕ��בւ���Ƃ��Ɉꎞ�I�Ɋi�[����
	double tyuuouti1, tyuuouti2;		//�����l�@�A

	printf("%d�̐�������͂��Ă�������\n", KAZU);
	//20�̐������͂������z�����͂���@
	for (int i = 1; i <= KAZU; i++) {
		
		printf("numbers1[%d]=", i);

		//�����ȊO�����͂��ꂽ�Ƃ��A�ē��͂�����
		while (scanf("%d", &numbers1[i]) != 1) {
			printf("��������͂��Ă��������B\n");
			while (getchar() != '\n'); // ���̓o�b�t�@���N���A
		}

		//���͂����l��0�����̎��A�ē��͂���
		while (numbers1[i] < 0) {
			printf("�ē��͂��Ă�������\n");
			printf("numbers1[%d]=", i);
			scanf("%d", &numbers1[i]);
		}

		sorted1[i] = numbers1[i];
		sum1 += numbers1[i];		//���v�l�@�����߂�
	}

	printf("\n%d�̐�������͂��Ă�������\n", KAZU);
	//20�̐������͂������z�����͂���A
	for (int i = 1; i <= KAZU; i++) {
		
		printf("numbers2[%d]=", i);

		//�����ȊO�����͂��ꂽ�Ƃ��A�ē��͂�����
		while (scanf("%d", &numbers2[i]) != 1) {
			printf("��������͂��Ă��������B\n");
			while (getchar() != '\n'); // ���̓o�b�t�@���N���A
		}

		//���͂����l��0�����̎��A�ē��͂���
		while (numbers2[i] < 0) {
			printf("�ē��͂��Ă�������\n");
			printf("numbers2[%d]=", i);
			scanf("%d", &numbers2[i]);
		}

		sorted2[i] = numbers2[i];
		sum2 += numbers2[i];	//���v�l�A�����߂�
	}

	max1 = numbers1[1];		//�ő�l�@��numbers1[1]��ݒ�
	min1 = numbers1[1];		//�ŏ��l�@��numbers1[1]��ݒ�

	max2 = numbers2[1];		//�ő�l�A��numbers2[1]��ݒ�
	min2 = numbers2[1];		//�ŏ��l�A��numbers2[1]��ݒ�

	//�ő�l�ƍŏ��l�����߂�@
	for (int i = 2; i <= KAZU; i++) {
		if (max1 < numbers1[i]) {
			max1 = numbers1[i];
		}
		if (min1 > numbers1[i]) {
			min1 = numbers1[i];
		}
	}

	//�ő�l�ƍŏ��l�����߂�A
	for (int i = 2; i <= KAZU; i++) {
		if (max2 < numbers2[i]) {
			max2 = numbers2[i];
		}
		if (min2 > numbers2[i]) {
			min2 = numbers2[i];
		}
	}

	
	heikin1 = (double)sum1 / KAZU;	//���ϒl�����߂�@

	heikin2 = (double)sum2 / KAZU;	//���ϒl�����߂�A

	//���U�����߂�@�A�A�����U�����߂�
	for (int i = 1; i <= KAZU; i++) {	
		bun1 += pow(numbers1[i] - heikin1, 2);
		bun2 += pow(numbers2[i] - heikin2, 2);
		bun12 += (numbers1[i] - heikin1) * (numbers2[i] - heikin2);
	}
	
	hyoujunn_hennsa1 = sqrt(bun1 / KAZU);	//�W���΍������߂�@

	hyoujunn_hennsa2 = sqrt(bun2 / KAZU);	//�W���΍������߂�A

	soukan_keisu = bun12 / (KAZU * hyoujunn_hennsa1 * hyoujunn_hennsa2);	//���֌W�������߂�
	
	//�R�s�[�����z��������ɕ��ѕς���
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
		sorted1[KAZU / 2];		//�����l�@�����߂�
	tyuuouti2 = (KAZU % 2 == 0) ?
		(sorted2[KAZU / 2 - 1] + sorted2[KAZU / 2]) / 2.0 :
		sorted2[KAZU / 2];		//�����l�A�����߂�

	printf("\n���v�l1�F%d\n", sum1);	//���v�l���o�͇@
	printf("���ϒl1�F%f\n", heikin1);	//���ϒl���o�͇@
	printf("�ŏ��l1�F%d\n", min1);	//�ŏ��l���o�͇@
	printf("�ő�l1�F%d\n", max1);	//�ő�l���o�͇@
	printf("�����l1�F%f\n", tyuuouti1);		//�����l�@���o��
	printf("�W���΍�1�F%f\n\n", hyoujunn_hennsa1);	//�W���΍����o�͇@

	printf("���v�l2�F%d\n", sum2);	//���v�l���o�͇A
	printf("���ϒl2�F%f\n", heikin2);	//���ϒl���o�͇A
	printf("�ŏ��l2�F%d\n", min2);	//�ŏ��l���o�͇A
	printf("�ő�l2�F%d\n", max2);	//�ő�l���o�͇A
	printf("�����l2�F%f\n", tyuuouti2);		//�����l�A���o��
	printf("�W���΍�2�F%f\n\n", hyoujunn_hennsa2);	//�W���΍����o�͇A

	printf("���֌W���F%f\n", soukan_keisu);		//���֌W�����o��

	return 0;

}