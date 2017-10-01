reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'size.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'bkdr 2k', \
'' using 4:xtic(1) with histogram title 'bkdr 4k', \
'' using 5:xtic(1) with histogram title 'bkdr 8k', \
'' using ($0-0.2):(0.075):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.2):(0.070):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.2):(0.065):4 with labels title ' ' textcolor lt 3, \
'' using ($0-0.2):(0.060):4 with labels title ' ' textcolor lt 4, \
