module PriorityEncoder(A,B,C,D,W,Y);
	input A,B,C,D;// Inputs
	output reg W,Y;// Outputs
	always @(A,B,C,D) begin// Logic Procedure
		W = (A|B);
		Y = (A|(C & ~B));
	end
endmodule