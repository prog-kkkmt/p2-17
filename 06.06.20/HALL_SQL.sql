/* По убыванию */
/*
select *
from HALL
order by HALL.CODE desc
*/

/*  По возрастанию */
/*
select *
from HALL
order by HALL.CODE asc
*/

/*  Максимальный CODE */
/*
select
    max(CODE)
from 
    HALL
/*
/* Вывод всех фильмов и их жанров*/
/*
select
    CODE as "Код зала",
    PLACE as "МЕСТ"
from HALL
order by HALL.CODE
*/

/* Вывод всех фильмов и их жанров по строкам */
/*
select
    'Зал: ' || CODE || ' Кол-во мест: ' || PLACE as "ЗАЛЫ"
from HALL
*/