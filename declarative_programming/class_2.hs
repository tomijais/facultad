div 5 2

-- same as

5 `div` 2


-- UNSAFE -> if empty list it breaks


-- get the first element of a list
head [1,2,3,4]
-- return 1



-- get everything but the first element
tail [1,2,3,4]
-- return [2,3,4]


-- get the nth
[1,2,3,4] !! 2
-- return 3


-- SAFE -> for every valid input theres a valid output

-- check if a list contains an element
elem 3 [1,2,4]

3 `elem` [1,2,4]
-- return False


-- calculate the length of a list
length [1,2,3]
-- return 3


-- reverse a list
reverse [1,2,3,4]
-- return [4,3,2,1]




-- drop the first n elements from a list
drop 3 [1,2,3, 4]

-- return [3, 4]


-- appending 2 list
[1,2] ++ [3,4]
(++) [1,2] [3,4]
-- return [1,2,3,4]


-- reverse a list
reverse [1,2,3,4]
-- return [4,3,2,1]




foo x y = x + (y * 2)
foo 2 3