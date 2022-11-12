# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE
    t1.*
FROM 
    Person AS t1
INNER JOIN
    Person AS t2
ON
    t1.email=t2.email

WHERE
    t1.id>t2.id;