// START: init logic
@256
D = A
@SP
M = D
@SP
D = M
D = D+1
@SP
M = D
// END: init logic
// START: writePushPop
@SP
D = M
D = D-1
@SP
M = D
@SP
A = M
A = A+1
M = 0
@SP
A = M
D = M
@-1
M = D
// END: writePushPop
// START: writePushPop
@SP
D = M
D = D-1
@SP
M = D
@SP
A = M
A = A+1
M = 0
@SP
A = M
D = M
@-1
M = D
// END: writePushPop
@SP
D = M
D = D-1
@SP
M = D
@SP
A = M
A = A+1
M = 0
@SP
A = M
D = M
@TMP
M = D
@SP
D = M
D = D-1
@SP
M = D
@SP
A = M
A = A+1
M = 0
@SP
A = M
D = M
@TMP
A = M
D = D+A
@SP
A = M
M = D
@SP
D = M
D = D+1
@SP
M = D
