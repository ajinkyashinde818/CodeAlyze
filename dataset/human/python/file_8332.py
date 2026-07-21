import Debug.Trace

main = do
 [[x,s] ,y] <- map ((map read ) .words). lines <$> getContents
 --[[x,w] ,[y]]<- map (map read.words).lines <$> getContents
 --trace (show $ zipWith (-) ( [last y] ++ init y) y) .print $ x + 1
 --trace (show . (-) x $ maximum.map (\s -> mod s x) $ zipWith (-) y ( [last y] ++ init y) ) .print $ x + 1

 print . (-) x $ maximum.map (\s -> mod s x) $ zipWith (-) y ( [last y] ++ init y)
