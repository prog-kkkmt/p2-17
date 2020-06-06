/*
select
    FM ||' '||substring(NA from 1 for 1)||'. '||substring(OT from 1 for 1)||'.' as FIO,
    SP
    from HERO
    order by SP desc
*/
/*
select 
    FM, NA, OT, SP
    from HERO
*/
/*
select FM, NA, OT, SP
    from HERO
    order by SP
*/
/*
select FM, NA, OT, SP
    from HERO
    order by NA
*/

/*
select
    avg(HERO.SP * 1.0)
from HERO
*/
/*
select
    max(SP)
from HERO
*/
/*
select ('2*2=' || cast(2*2 as char(2))) as "Произведение"
from rdb$database
*/
