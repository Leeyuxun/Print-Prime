#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include<sys/time.h>
unsigned long long main(){
	unsigned long long n = pow(2,34);	//打印素数范围 	
	unsigned long long i;	//辅助参数 
	unsigned long long j;	//辅助参数 	
    bool *a = (bool*)malloc( n*sizeof(bool) );	//声明bool型动态数组*a，节省空间   
    //初始化计时器 
    struct timeval start;
    struct timeval end;
    unsigned long long timer;   
    //计时开始 
    gettimeofday(&start, NULL);   
    // 初始化数组*a 
    for (i = 2; i <= n; i++) {
        a[i] = true;
    }
	//新建prime文件,用于存放素数 
	FILE *fpWrite=fopen("prime","w"); 
	// 开始判断是否为素数
    for (i = 2; i <= sqrt(n); i++){
        if (a[i]){
        	for (j = i; j*i <= n; j++) {	//判定i的倍数全为合数
				a[j*i] = false;
			}
		} 
    }
    //根据数组*a的值打印范围内所有素数
    for (i = 2; i <= n; i++){
        if (a[i]){
        	fprintf(fpWrite,"%llu\t",i);	//将素数写入到prime文件下
		}
    }
    free; 	//释放动态数组
	//计时结束	
	gettimeofday(&end, NULL);
	//计算打印素数的用时 
	timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fpWrite,"\n\n timer = %ld us\n", timer);
    fclose(fpWrite);  //关闭prime文件 
} 
