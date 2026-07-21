import System.IO
import Data.List

type CookieCount = Integer
type YuckCount = CookieCount
type YummyCount = CookieCount
type PoisonedCount = CookieCount

countUpTargetCookies :: (YuckCount, YummyCount, PoisonedCount) -> CookieCount
countUpTargetCookies (yuck, yummy, poisoned) = yummy + poisoned

eatableCount :: YuckCount -> YummyCount -> PoisonedCount -> (YuckCount, YummyCount, PoisonedCount)
eatableCount yuck yummy poisoned
  | poisoned <= (unpoisoned) = (yuck, yummy, poisoned)
  | poisoned >  (unpoisoned) = (yuck, yummy, unpoisoned + 1)
  where unpoisoned = yuck + yummy

main = do
  args <- getLine
  let stringArray = words args
  let [yuck, yummy, poisoned] = [read numberStr | numberStr <- stringArray]
  putStr . show $ countUpTargetCookies (eatableCount yuck yummy poisoned)
