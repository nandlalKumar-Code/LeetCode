# Write your MySQL query statement below
SELECT 
    t1.score,
    (
        SELECT 
            COUNT(DISTINCT t2.score)
        FROM
            Scores as t2
        WHERE
            t2.score>=t1.score
    ) AS 'rank'
FROM
    Scores as t1
ORDER BY t1.score DESC;