module mux2(
   input a,b,s,
   output reg y //  y = s'a + sb  (not really a register)
    );
always @(a,b,s) begin
    y = ((~s & a) | (s & b));// add code here to implement the multiplexer y = s'a + sb
end
endmodule
