-- Write your PostgreSQL query statement below
select u.unique_id, 
        e.name
from employees e
    LEFT JOIN employeeUNI u ON e.id = u.id