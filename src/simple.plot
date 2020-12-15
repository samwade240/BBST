set terminal postscript color
set output "output.ps"
set title "AVL Tree Remove"
set xlabel "Size (N)"
set ylabel "Time (seconds)"
plot [:][:] "data.out" using 1:2 with line
