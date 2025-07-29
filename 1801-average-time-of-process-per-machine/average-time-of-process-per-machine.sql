-- Write your PostgreSQL query statement below
select a.machine_id,
        ROUND(AVG(b.timestamp - a.timestamp)::numeric, 3) as processing_time
from activity a
JOIN activity b
ON a.machine_id =  b.machine_id
AND a.process_id = b.process_id
AND a.activity_type = 'start'
AND b.activity_type = 'end'
group by a.machine_id