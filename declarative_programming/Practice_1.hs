add x y = x + y
mul x y = x * y

second :: [a] -> a
-- second [] = []
-- second (x:xs) = []
second (x:y:xs) = y