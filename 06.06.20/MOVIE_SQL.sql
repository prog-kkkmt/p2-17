/* По убыванию */
/*
select *
from MOVIE
order by MOVIE.CODE desc
*/

/*  По возрастанию */
/*
select *
from MOVIE
order by MOVIE.CODE asc
*/

/*  Максимальный CODE */
/*
select
    max(CODE)
from 
    MOVIE
/*
/* Вывод всех фильмов и их жанров*/
/*
select
    NAME as "Название",
    GENRE as "Жанр"
from MOVIE
order by NAME
/*

/* Вывод всех фильмов и их жанров по строкам */
/*
select
    'Название: ' || NAME || ' Жанр: ' || GENRE as "ФИЛЬМЫ"
from MOVIE
*/
/*
select ('2+2=' || cast(2+2 as char(2))) as "Сумма
from rdb$database
*/

