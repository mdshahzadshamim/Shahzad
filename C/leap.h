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

int day_count(int month, int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
    else if(month == 2)
    {
        if(leap(year) == 1)
        return 29;
        else if(leap(year) == 0)
        return 28;
    }
}