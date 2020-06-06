/*
select *
from sostav
*/

--по возрастанию
/*
select *
from sostav
order by sostav.code_sost
*/


--в порядке уменьшения
/*
select *
from sostav
order by sostav.code_sost desc
*/

/*
select code_sost as "Код состава",
ky as "Код узла",
kpy as "Код подузла",
KOLVO as "Количество",
pos as "Позиция"
from sostav
order by code_sost
*/

--наибольшее количество
/*
select
max(kolvo)
from
sostav
*/
