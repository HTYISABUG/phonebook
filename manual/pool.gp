reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'pool.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'bkdr'                      , \
'' using 4:xtic(1) with histogram title 'bkdr + reduce'             , \
'' using 5:xtic(1) with histogram title 'bkdr + reduce + pool'      , \
'' using ($0 - 0.2):(0.070):2 with labels title ' ' textcolor lt 1  , \
'' using ($0 - 0.2):(0.065):3 with labels title ' ' textcolor lt 2  , \
'' using ($0 - 0.2):(0.060):4 with labels title ' ' textcolor lt 3  , \
'' using ($0 - 0.2):(0.055):5 with labels title ' ' textcolor lt 4
