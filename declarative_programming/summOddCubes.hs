summOddCubes :: [Int] -> Int
summOddCubes xs = sum(map (^3) (filter odd xs) )

summOddCubes xs = sum [x^3 | x <- xs, odd x]

summOddCubes xs = sum $ map (^3)  $ filter odd xs
