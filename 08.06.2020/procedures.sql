insert into cities(city_code, distance, rate_code)
values (5, 700, 4)

update cities
    set
       cities.distance = cities.distance + 100
    where cities.rate_code = 3;

delete from cities
where cities.city_code = 2;

commit;
