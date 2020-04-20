#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include<sys/time.h>
unsigned long long main(){
	unsigned long long n = pow(2,34);	//��ӡ������Χ 	
	unsigned long long i;	//�������� 
	unsigned long long j;	//�������� 	
    bool *a = (bool*)malloc( n*sizeof(bool) );	//����bool�Ͷ�̬����*a����ʡ�ռ�   
    //��ʼ����ʱ�� 
    struct timeval start;
    struct timeval end;
    unsigned long long timer;   
    //��ʱ��ʼ 
    gettimeofday(&start, NULL);   
    // ��ʼ������*a 
    for (i = 2; i <= n; i++) {
        a[i] = true;
    }
	//�½�prime�ļ�,���ڴ������ 
	FILE *fpWrite=fopen("prime","w"); 
	// ��ʼ�ж��Ƿ�Ϊ����
    for (i = 2; i <= sqrt(n); i++){
        if (a[i]){
        	for (j = i; j*i <= n; j++) {	//�ж�i�ı���ȫΪ����
				a[j*i] = false;
			}
		} 
    }
    //��������*a��ֵ��ӡ��Χ����������
    for (i = 2; i <= n; i++){
        if (a[i]){
        	fprintf(fpWrite,"%llu\t",i);	//������д�뵽prime�ļ���
		}
    }
    free; 	//�ͷŶ�̬����
	//��ʱ����	
	gettimeofday(&end, NULL);
	//�����ӡ��������ʱ 
	timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fpWrite,"\n\n timer = %ld us\n", timer);
    fclose(fpWrite);  //�ر�prime�ļ� 
} 
