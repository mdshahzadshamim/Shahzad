/*THE FUNCTION BELOW REPLACES ALL THE OCCURENCES OF A SUB-STRING 
IN A STRING AND RETURNS THE UPDATED STRING*/
char *rep(char *str, const char *find, const char *repwth)
{
    char *k; int i = 0;

    // printf("Length of String : %d\n",strlen(str));

    k = strstr(str, find);
    while(k != NULL)    
    {
        i++;        
        k = strstr(k + strlen(find), find);
    }
    
    if(i == 0) return str;

    char *temp;
    temp =  (char *)malloc(strlen(str) + 1 + (strlen(repwth) - strlen(find)) * i );
    if(temp == NULL) perror;
    strcpy(temp, "\0");
    
    char *p;
    p = strstr(str, find);//1. Find Occurence First

    while(p != NULL)
    {
        strncat(temp, str, p-str);//2. Copy up to there
        strcat(temp, repwth);//3. Copy the sub-string
        str = p + strlen(find);
        p = strstr(str, find);//1. Find Occurence
    }

    strcat(temp, str);//4. Copy the rest

    // printf("Length of Temp : %d\n",strlen(temp));

    str = temp;
    return str;
}
