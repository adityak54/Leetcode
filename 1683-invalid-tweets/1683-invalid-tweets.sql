# Write your MySQL query statement below
SELECT tweet_id FROM Tweets AS T 
WHERE length(T.content)>15
