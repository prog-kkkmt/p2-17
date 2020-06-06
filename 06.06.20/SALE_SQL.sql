/* По убыванию */
/*
select *
from SALE
order by SALE.CODE_SALE desc
*/

/*  По возрастанию */
/*
select *
from SALE
order by SALE.CODE_SALE asc
*/

/*  Максимальный CODE */
/*
select
    max(CODE_SALE)
from 
    SALE
/*
/* Вывод всех фильмов и их жанров*/
/*
select
    CODE_MOVIE as "Код фильма",
    CODE_HALL as "Зал",
    TIME_MOVIE as "Время"
from SALE
order by SALE.CODE_SALE
*/

/* Вывод всех фильмов и их жанров по строкам */

select
    'Зал: ' || CODE_HALL || ' Код фильма: ' || CODE_MOVIE || ' Время: ' || TIME_MOVIE as "Билет"
from SALE



