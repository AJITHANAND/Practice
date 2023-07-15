from calendar import *

month,day,year = map(int,input().split())
day_idx = weekday(year,month,day)
print(day_name[day_idx].upper())