biggest :: Ord a => a -> a -> a -> a -> a
biggest w x y z = 
    if w >= x && w >= y && w >= z
    then w
    else if x >= y && x >= z
    then x
    else if y >= z
    then y
    else z


-- biggest :: Int -> Int -> Int -> Int
-- biggest x y z =
--     if x >= y && x >= z
--     then x
--     else if y >= x && y >= z
--     then y
--     else z




-- biggest :: Ord a -> a -> a -> a
-- biggest x y z =
--     if x >= y && x >= z
--     then x
--     else if y >= x && y >= z
--     then y
--     else z




 