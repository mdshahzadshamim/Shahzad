fp);
    for(int i = 0; i < N + N/5; i++)
    {
        fread(&s, strsize, 1, fu);
        fread(&y, strsize, 1, fp);
        printf("\n%2d --- ", y.roll);
        if(y.roll == s.roll || (s.roll > N && y.roll == N))
        printf("%2d", s.roll);
        else fseek(fu, -strsize, SEEK_CUR);
    }