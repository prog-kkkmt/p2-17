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

select FM, NA, OT, SP
    from HERO
    order by NA