#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	// check if there is no text1
	int check = 0;
	check = stat("text1", &stat1);

	if(check != 0)
	{
		printf("Error : there is no text1\n");
	}
	return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	// check if there is no text2
	int check = 0;
	check = stat("text2", &stat2);

	if(check != 0)
	{
		printf("Error : there is no text2\n");
	}
	return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	time1 = localtime(&stat1.st_mtime);
	return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);
	return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("size compare\n");
	//variable declare
	long long int text1_size;
	long long int text2_size;
	
	//variable initialize
	text1_size = stat1.st_size;
	text2_size = stat2.st_size;
	if(text1_size > text2_size)
		printf("text1 is bigger\n");
	else if(text1_size < text2_size)
		printf("text2 is bigger\n");
	else
		printf("same size\n");

	printf("\n");
	return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	printf("block compare\n");
	//variable declare
	long long int text1_block_size;
	long long int text2_block_size;
	//variable initialize
	text1_block_size = stat1.st_blocks;
	text2_block_size = stat2.st_blocks;

	if(text1_block_size > text2_block_size)
		printf("text1 is bigger\n");
	else if(text1_block_size < text2_block_size)
		printf("text2 is bigger\n");
	else
		printf("same size\n");

	printf("\n");
	return;
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	printf("date compare\n");
	// compare tm_mon
	if(time1->tm_mon > time2->tm_mon)
		printf("time1 is early \n");
	else if(time1->tm_mon < time2->tm_mon)
		printf("time2 is early \n");
	else{
		// compare tm_mday
		if(time1->tm_mday > time2->tm_mday)
			printf("time1 is early \n");
		else if(time1->tm_mday < time2->tm_mday)
			printf("time2 is early \n");
		// same date
		else
			printf("same time \n");
	}
	printf("\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	printf("time compare\n");
	// compare hour
	if(time1->tm_hour > time2->tm_hour)
		printf("time1 is early \n");
	else if(time1->tm_hour < time2->tm_hour)
		printf("time2 is early \n");
	else{
		// compare minutes
		if(time1->tm_min > time2->tm_min)
			printf("time1 is early \n");
		else if(time1->tm_min < time2->tm_min)
			printf("time2 is early \n");
		// same time
		else
			printf("same time \n");

	}
}
