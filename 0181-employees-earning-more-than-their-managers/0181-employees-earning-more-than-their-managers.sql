# Write your MySQL query statement below
SELECT
    t1.name AS 'Employee'
FROM
    Employee AS t1
INNER JOIN
    Employee AS t2
ON t1.ManagerId=t2.Id
WHERE
    t1.salary>t2.salary;