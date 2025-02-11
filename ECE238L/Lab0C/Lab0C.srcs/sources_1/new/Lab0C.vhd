----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/11/2025 02:28:38 PM
-- Design Name: 
-- Module Name: Lab0C - Boolean_Function
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

entity Lab0C is
    Port ( A,B : in STD_LOGIC;
           F_NOT, F_AND, F_OR : out STD_LOGIC);
end Lab0C;

architecture Boolean_Function of Lab0C is

begin

    F_NOT <=  a NAND a;
    F_AND <= (A NAND B) NAND (A NAND B);
    F_OR <=  (A NAND A) NAND (B NAND B);


end Boolean_Function;
