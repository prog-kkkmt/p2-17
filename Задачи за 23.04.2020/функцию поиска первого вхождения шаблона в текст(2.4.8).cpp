int strstr(const char *text, const char *pattern)
{
/**etext - номер '\0' элемента в строке; epattern - номер '\0' элемента в шаблоне; k - счетчик**/
    int etext = 0, epattern = 0, k = 0;

/**Создем бесконечный цикл, условием выхода из которого является нахождение номре '\0' символа**/
    for(int i = 0; i >= 0; i++)
    {
        if(text[i] == '\0')
        {
            etext = i;
            break;
        }
    }
    for(int i = 0; i >= 0; i++)
    {
        if(pattern[i] == '\0')
        {
            epattern = i;
            break;
        }
    }

/**Проверка на наличие шаблона**/
    if(epattern == 0)
        return 0;

/**Проверка на размер шаблона**/
    if(etext - epattern < 0)
        return -1;

/**Запускаем цикл на проход строки и поиска в ней шаблона**/
    for(int i = 0; i < (etext - epattern + 1); i++)
    {
        k = 0;
        for(int j = 0; j < epattern; j++)
        {
/**Условие на нахождения начала вхождения шаблона в строку**/
            if(text[i + j] == pattern[j])
                k++;
            else
                break;
        }
/**Если нашли, выводим номер позиции вхождения**/
        if(k == epattern)
            return i;
    }
    return -1;
}
