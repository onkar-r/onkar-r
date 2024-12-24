select * from yb_servers();
select version();

execute snap_reset;
-- Queries
execute snap_table;

explain (costs off,analyze,verbose)
select c1, c2 from t where c1 = 10;

