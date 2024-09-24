(^^^) :: Int -> Int -> Int
(^^^) m 0 = 1
(^^^) m 1 = m
(^^^) 0 n = n
(^^^) 1 n = 1
(^^^) m n = m * ((^^^) m (n-1))


euclid :: (Integral a, Ord a) => a -> a -> a
euclid n m
    | n == m = n
    | m > n = euclid(m-n) n
    | otherwise = euclid m (n-m)