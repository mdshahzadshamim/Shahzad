#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include <sys/time.h>

int main()
{
    clock_t start, end;

    start = clock();

    double totaltime;

    time_t now = time(NULL); printf("Time : %ld\n",now);

    sleep(1);

    time_t now2 = time(NULL); printf("After 1 sec : %ld\n",now2);

    double diff = difftime(now2,now); printf("Time difference : %f\n",diff);

    struct tm *gmt_time = gmtime(&now); char *gmt_time_string = asctime(gmt_time); printf("GMT Day, Date & Time : %s\n",gmt_time_string);
    
    char *current_time_string = ctime(&now); printf("Day, Date & Time : %s\n",current_time_string);

    struct tm *lct = localtime(&now);
    printf("Secs after the minute : %d\n",lct->tm_sec);
    printf("Mins after the hour : %d\n",lct->tm_min);
    printf("Hours since midnight : %d\n",lct->tm_hour);
    printf("Day of the month : %d\n",lct->tm_mday);
    printf("Months since January : %d\n",lct->tm_mon);
    printf("Years since 1900 : %d\n",lct->tm_year);
    printf("Days since Sunday : %d\n",lct->tm_wday);
    printf("Days since January 1 : %d\n",lct->tm_yday);
    printf("Daylight Savings Time Flag : %d\n",lct->tm_isdst);

    end = clock();

    totaltime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTotal Time: %f\n",totaltime);

    return 0;
}

/*
int main() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    long milliseconds = currentTime.tv_usec / 1000; // Extract milliseconds from microseconds field

    // Convert the time value to a human-readable format
    char buffer[30];
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", localtime(&currentTime.tv_sec));

    // Print the current time with milliseconds
    printf("Current Time: %s.%03ld\n", buffer, milliseconds);

    return 0;
}
*/