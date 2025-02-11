----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/11/2025 03:02:31 PM
-- Design Name: 
-- Module Name: Lab1A - Boolean_Function
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Lab1A is
    Port ( A,B : in STD_LOGIC;
           F_E, F_G, F_L : out STD_LOGIC);
end Lab1A;

architecture Boolean_Function of Lab1A is

begin

    F_E <=  ((NOT A) AND (NOT B)) OR (A AND B);
    F_G <= (NOT B) AND A;
    F_L <=  B AND (NOT A);

end Boolean_Function;
