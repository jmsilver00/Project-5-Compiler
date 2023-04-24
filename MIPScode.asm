.data
	CHAR: .byte 'c'
	fval: .float 10.500000
.text
main:
# -----------------------
li $v0, 4
la $a0, CHAR
syscall
li $a0, 10
li $v0, 11
syscall

li $t6,2982
move $a0,$t6
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $v0, 2
lwc1 $f12, fval
syscall
li $v0, 10
li $v0, 11
syscall

li $t5,28

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,26

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,24

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,22

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,20

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,18

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,16

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,14

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,12

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,10

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,8

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,6

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,4

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,2

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t5,0

move $a0,$t5
li $v0,1
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
