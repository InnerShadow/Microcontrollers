rem
rem avr-objdump.exe -x sketch_mar23b.ino.hex >t1.txt
rem avr-objdump.exe -x -D sketch_mar23b.ino.hex >t2.txt
rem avr-objdump.exe -x -m avr -D sketch_mar23b.ino.hex >t3.txt
avr-objdump.exe -x -m avr -d sketch_mar23b.ino.elf >t4.txt
