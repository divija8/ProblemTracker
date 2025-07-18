# Write your MySQL query statement below
select 
    w2.id as Id
from weather w1, weather w2 
where w2.temperature > w1.temperature and 
        DATEDIFF(w2.recordDate, w1.recordDate) = 1