int power(int x, unsigned p) {
    int answer = 1;
    if (p == 0)
    {
        answer = 1;
    }
    else if (x == 0)
    {
        answer = 0;
    }
    else
    {
        for(int i = 0; i < p; i++)
        {
            answer *= x;
        }
    }
    return answer;
}
