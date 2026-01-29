/*
addersubtractor.v
Developed By: Derek Johnston @ Texas Tech University

Implement an 4-bit Ripple-Carry Adder/Subtractor

Inputs: A (4-bit), B (4-bit), C (1-bit)
Output: S (4-bit) = A + B (C = 0), A - B (C = 1)
*/

//code cell like in jupiter
module full_adder(A, B, C, F, G); //Make Function and declare ports
	/* Code Here */
	input A,B,C; //Declare Inputs
	output F,G; //Declare Outputs

	assign F = A ^ B ^ C; //Defining Variables
	assign G = B & C|A & B|A & C; //Defining Variables

endmodule //end module

module top(A, B, C, S); //making another module and declaring ports for module (ports are like int declaring what variables are going to be used)
	/* Code Here */
	input [3:0] A,B; //RECALL:[3:0] is declaring A and B to be four bits (0-3 is 4 "values") A=0000 B=0000
	input C; 
	output [3:0] S; //declaring S is a four bit output
	wire C1, C2, C3, C4; //wire is connection; 

	//full_adder U0 is calling the function; the U0 is the instance. (0: The first time you call it, 1: the next time you call it, etc.)
	//The "." in .A(A[0]) assigns port A to what is inside the parantheses

	//A[0]; 0 is the index of the four bit number (refrence RECALL)
	//ex: A=1234 A[0]=1

	//testbench gives the variables values 
	//reg means register gives the value assigned to it output will just declare it as a output

	//this math is being replicated from a the full adder constructed in class
	full_adder U0 (.A(A[0]), .B(B[0]^C), .C(C), .F(S[0]), .G(C1)); //wire C1 replace value of port G
	full_adder U1 (.A(A[1]), .B(B[1]^C), .C(C1), .F(S[1]), .G(C2));
	full_adder U2 (.A(A[2]), .B(B[2]^C), .C(C2), .F(S[2]), .G(C3));
	full_adder U3 (.A(A[3]), .B(B[3]^C), .C(C3), .F(S[3]), .G(C4));
endmodule