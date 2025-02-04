----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/04/2025 03:30:48 PM
-- Design Name: 
-- Module Name: Lab0A - Booleab_Function
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

entity Lab0A is
    Port ( A,B : in STD_LOGIC;
           F_NOT,F_AND,F_OR : out STD_LOGIC);
end Lab0A;

architecture Booleab_Function of Lab0A is

begin
    F_NOT <= not A;
    F_AND <= A and B;
    F_OR <= A or B;


end Booleab_Function;
