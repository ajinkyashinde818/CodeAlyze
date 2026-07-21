import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T
import Data.Bool (bool)

main :: IO ()
main = do
  s <- T.getLine :: IO T.Text
  (q : _) <- map unsafeTextToInt . T.words <$> T.getLine :: IO [Int]
  queries <- sequence . replicate q $ query . T.words <$> T.getLine :: IO [Query]
  let
    result :: (Bool, String, String)
    result = foldl step (True, "", "") $ queries
      where
        step :: (Bool, String, String) -> Query -> (Bool, String, String)
        step (b, pf, sf) = g
          where
            g Reverse   = (not b, sf, pf)
            g (Cons c)  = (b, c : pf, sf)
            g (Snoc c)  = (b, pf, c : sf)
    (b, pf, sf) = result
  putStr pf
  T.putStr . bool T.reverse id b $ s
  putStrLn . reverse $ sf

data Query = Reverse | Cons Char | Snoc Char

query :: [T.Text] -> Query
query = arguments . command
  where
    command (cmd : args) = (unsafeTextToInt cmd, args)
    arguments (1, _)                = Reverse
    arguments (_, args) | f == 1    = Cons c
                        | otherwise = Snoc c
      where
        (f, c) = pairMap unsafeTextToInt T.head fc
          where
            fc = unsafeListToTuple args

pairMap :: (a -> a') -> (b -> b') -> (a, b) -> (a', b')
pairMap f g (x, y) = (f x, g y)

unsafeUncons :: [a] -> (a, [a])
unsafeUncons (x : xs) = (x, xs)

unsafeListToTuple :: [a] -> (a, a)
unsafeListToTuple (x : y : _) = (x, y)

unsafeTextToInt :: T.Text -> Int
unsafeTextToInt s = case T.signed T.decimal s of
  Right (n, _) -> n
