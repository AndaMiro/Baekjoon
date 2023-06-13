#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	int heard_eung_ae_cnt, ready_eung_ae;
} Student, *PStudent;

void eung_ae(PStudent PS, int N) {
	for (int i = 0; i < N; i++) {
		int nm1 = i - 1 < 0 ? N - 1 : i - 1, np1 = i + 1 >= N ? 0 : i + 1;
		if (PS[i].ready_eung_ae) {
			PS[nm1].heard_eung_ae_cnt++;
			PS[np1].heard_eung_ae_cnt++;
			PS[i].ready_eung_ae = 0;
		}
	}

	for (int j = 0; j < N; j++) {
		if (PS[j].heard_eung_ae_cnt >= 2) {
			PS[j].ready_eung_ae = 0;
		}
		else if (PS[j].heard_eung_ae_cnt == 1) PS[j].ready_eung_ae = 1;
		PS[j].heard_eung_ae_cnt = 0;
	}
}

int main(void) {
	int N, M;
	long long K;
	PStudent students;

	scanf("%d %d  %lld", &N, &M, &K);
	students = (PStudent)malloc(sizeof(Student) * N);
	memset(students, 0, sizeof(Student) * N);
	int tmp;
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		students[tmp].ready_eung_ae = 1;
	}
	
	for (int j = 0; j < K; j++) eung_ae(students, N);

	int cnt = 0;
	for (int k = 0; k < N; k++) if (students[k].ready_eung_ae) cnt++;
	printf("%d", cnt);
	
	free(students);
	return 0;
}
