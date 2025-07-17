# Write your MySQL query statement below
select
    e.name,
    b.bonus
from employee e
    LEFT JOIN bonus b ON e.empID = b.empID
where b.bonus < 1000 or b.bonus IS NULL