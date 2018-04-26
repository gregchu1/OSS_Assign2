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
	printf("size compare\n");
	sizecmp();
	printf("\n");
	printf("block compare\n");
	blockcmp();
	printf("\n");
	printf("date compare\n");
	datecmp();
	printf("\n");
	printf("time compare\n");
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	int check = 0;
	check = stat("test1", &stat1);

	if(check != 0)
	{
		printf("Error\n");
	}
	return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	int check = 0;
	check = stat("text2", &stat2);

	if(check != 0)
	{
		printf("Error\n");
	}
	return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	struct tm* time1;
	struct stat buf;
	int check = 0;

	stat("text1", &buf);

	check = stat("text1", &stat1);

	if (check != 0) {
		printf("Error\n");
	}

	time1 = localtime(&buf.st_mtime);

	return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	struct tm* time2;
	struct stat buf;
	int check = 0;

	stat("text2", &buf);

	check = stat("text2", &stat2);

	if (check != 0) {
		printf("Error\n");
	}

	time2 = localtime(&buf.st_mtime);

	return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	//variable declare
	long long int text1_size;
	long long int text2_size;
	//variable initialize
	text1_size = stat1.st_size;
	text2_size = stat2.st_size;

	if(text1_size > text2_size)
		printf("text1 is bigger\n");
	else
		printf("text2 is bigger\n");
	return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	//variable declare
	long long int text1_block_size;
	long long int text2_block_size;
	//variable initialize
	text1_block_size = stat1.st_blocks;
	text2_block_size = stat2.st_blocks;

	if(text1_block_size > text2_block_size)
		printf("text1 is bigger\n");
	else
		printf("text2 is bigger\n");
	return;
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	// get file time data
	filetime1();
	filetime2();
	// compare tm_year
	if(time1->tm_year > time2->tm_year)
		printf("time1 is early \n");
	else if(time1->tm_year < time2->tm_year)
		printf("time2 is early \n");
	else{
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
			// dates are same
			else
				printf("same time \n");
		}
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	// get file time data
	filetime1();
	filetime2();
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
		else{
			// compare seconds
			if(time1->tm_sec > time2->tm_sec)
				printf("time1 is early \n");
			else if(time1->tm_sec < time2->tm_sec)
				printf("tome2 is early \n");
			// times are same
			else
				printf("same time \n");
		}
	}
}
