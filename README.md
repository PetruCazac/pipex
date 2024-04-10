# pipex

This program is about understanding how pipes work in Linux, processes, forks, file descriptors and wait command.
----------------------------------------------------------
Usage : 

./pipex infile "cmd1" "cmd2" outfile 

it is equivalent to:

< infile cmd1 | cmd2 > outfile

------------------------------------------------------------
Example from the subject: 
./pipex infile "grep a1" "wc -w" outfile

Should behave like: < infile grep a1 | wc -w > outfile
