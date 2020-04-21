// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p) 
{
	if (p == 0)
    {
        return 1;
    }
	
    int answer = x;
    
    for (int i = 1; i < p; ++i)
    {
        answer *= x;
    }
    
    return answer;
}
