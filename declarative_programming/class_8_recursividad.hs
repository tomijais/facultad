length' :: [a] -> Int
length' [] = 0
length' x = 1 + length' (tail x)


reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x, xs) = reverse' xs ++ [x]