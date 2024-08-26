-- how to sum in haskell from 1 to 10
-- sum[1...10]

-- this is an infix functino of two arguments
f [] = []
f (x:xs) = f ys ++ [x] ++ f zs
    where
    ys = [a | a  <- xs, a <=x]
    zs = [b | b <-xs, b > x]

-- the ++ concatenates
-- [1,2,3] ++ [4,5,6] = [1,2,3,4,5,6]
-- [1,2,3] ++ [] = [1,2,3]


