// 4-bit up/down counter
module Count4(clk,rst,enable,upDown, count);
   input clk, rst, enable, upDown;
   output reg [3:0] count;

   // insert code here 
   always@(posedge clk) begin
      casex ({rst,enable,upDown})
      3'b1XX:count=0000;
      3'b00X:count=count;
      3'b010:count=count-1;
      3'b011:count=count+1;
      endcase
   end
endmodule  // Count4