-- Write your PostgreSQL query statement below
select e.name,
        b.bonus
from employee e
LEFT JOIN bonus b
ON e.empId = b.empId
where b.bonus is null
or b.bonus < 1000