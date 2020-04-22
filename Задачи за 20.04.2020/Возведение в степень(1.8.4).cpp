// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//
int power(int x, unsigned p) {
    int ansver = 1;
    for(int i = 0; i < p; i++)
    {
        ansver = ansver * x;
    }
    return ansver;
}
