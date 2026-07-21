import qualified Data.ByteString.Char8 as BS
import qualified Data.Maybe as MA

main = do
    [k, n] <- fmap (fst . MA.fromJust . BS.readInt) . BS.words <$> BS.getLine
    a:as' <- fmap (fst . MA.fromJust . BS.readInt) . BS.words <$> BS.getLine
    let as = a:as'
    let bs = as' ++ [a]
    putStrLn $ show (k - maximum (fmap (\(a, b) -> if abs (a - b) > k `div` 2 then k - abs (a - b) else abs (a - b)) $ zip as bs))
