import qualified Data.ByteString.Char8 as BS
import qualified Data.Maybe as MA

main = do
    [n, r] <- fmap (fst . MA.fromJust . BS.readInt) . BS.words <$> BS.getLine :: IO [Int]
    putStrLn . show $ if n >= 10 then r else r + 100 * (10 - n)
