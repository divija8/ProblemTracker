# Write your MySQL query statement below
select 
    r.contest_id,
    round(100.0 * count(distinct u.user_id)/(select COUNT(user_id) from users), 2) as percentage from users u JOIN
    register r on u.user_id = r.user_id
    group by contest_id
    order by percentage desc, r.contest_id ASC