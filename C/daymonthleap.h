int leap(int year)
{
    if(year%100 == 0)
    {
        if(year%400 == 0)
        return (1);
        else
        return (0);
    }
    else
    {
        if(year%4 == 0)
        return (1);
        else
        return (0);
    }
}
int month(int i)
{
    switch(i)
    {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }
}

int day(int i)
{
    switch(i)
    {
        case 1:
            printf("Sunday");
            break;
        case 2:
            printf("Monday");
            break;
        case 3:
            printf("Tuesday");
            break;
        case 4:
            printf("Wednesday");
            break;
        case 5:
            printf("Thursday");
            break;
        case 6:
            printf("Friday");
            break;
        case 7:
            printf("Saturday");
            break;
    }
}
int month_days(int i, int year)
{
    int days;
    switch(i)
    {
        case 1:
            days = 31;
            break;
        case 2:
            if(leap(year) == 0) days = 28;
            else if(leap(year) == 1) days = 29;
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
    }
    return(days);
}
int day_short(int i)
{
    switch(i)
    {
        case 7:
            printf("Sun");
            break;
        case 1:
            printf("Mon");
            break;
        case 2:
            printf("Tue");
            break;
        case 3:
            printf("Wed");
            break;
        case 4:
            printf("Thu");
            break;
        case 5:
            printf("Fri");
            break;
        case 6:
            printf("Sat");
            break;
    }
}