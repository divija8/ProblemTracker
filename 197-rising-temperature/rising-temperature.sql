-- Write your PostgreSQL query statement below
SELECT 
    w2.id AS Id
FROM 
    weather w1
JOIN 
    weather w2 
    ON w2.recordDate - w1.recordDate = 1
WHERE 
    w2.temperature > w1.temperature;